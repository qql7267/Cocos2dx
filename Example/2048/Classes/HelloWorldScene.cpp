#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#define TOUCH_LONG 50
#define TOUCH_SHORT 10
#define CARD_BORDER 4

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	auto size = Director::getInstance()->getVisibleSize();
	int width = size.width;
	int height = size.height;
	int cardSize = (width - 20) / 4;

	auto* background = LayerColor::create(Color4B(255, 255, 255, 255));
	addChild(background);

	auto* baseBG = LayerColor::create(Color4B(186, 191, 191, 255), width - 20, width - 20);
	baseBG->setPosition(10, (height - 100 - width - 10) / 2);
	addChild(baseBG);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			card[i][j] = CardSprite::createCardSprite(0, cardSize, cardSize * i + CARD_BORDER / 2, cardSize * j + CARD_BORDER / 2);
			baseBG->addChild(card[i][j]);
		}
	}

	record = UserDefault::sharedUserDefault()->getIntegerForKey("record");
	demo = 2048;
	score = 0;

	broad1 = ScoreBroad::createScoreBroad(demo, 120, 90, "", 1, 15, 540);
	addChild(broad1);
	broad2 = ScoreBroad::createScoreBroad(record, 90, 90, "high", 2, 150, 540);
	addChild(broad2);
	broad3 = ScoreBroad::createScoreBroad(score, 90, 90, "score", 2, 255, 540);
	addChild(broad3);

	this->createCard();
	this->createCard();

	this->isLock = false;
	auto* dispatcher = Director::getInstance()->getEventDispatcher();
	auto* listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
}
bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
	this->x = touch->getLocation().x;
	this->y = touch->getLocation().y;
	return true;
}
void HelloWorld::onTouchMoved(Touch *touch, Event *unused_event)
{
	if (!isLock)
	{
		float dx = touch->getLocation().x - this->x;
		float dy = touch->getLocation().y - this->y;
		if (dx > TOUCH_LONG&&fabs(dy) < TOUCH_SHORT)
		{
			if(doRight())
				createCard();
			this->isLock = true;
		}
		else if (dx < -TOUCH_LONG&&fabs(dy) < TOUCH_SHORT)
		{
			if (doLeft())
				createCard();
			this->isLock = true;
		}
		else if (dy > TOUCH_LONG&&fabs(dx) < TOUCH_SHORT)
		{
			if (doUp())
				createCard();
			this->isLock = true;
		}
		else if (dy < -TOUCH_LONG&&fabs(dx) < TOUCH_SHORT)
		{
			if (doDown())
				createCard();
			this->isLock = true;
		}
	}
}
void HelloWorld::onTouchEnded(Touch *touch, Event *unused_event)
{
	this->isLock = false;
}
void HelloWorld::createCard()
{
	int i = CCRANDOM_0_1() * 4;
	int j = CCRANDOM_0_1() * 4;
	if (card[i][j]->getNumber() > 0)
	{
		createCard();
	}
	else
	{
		card[i][j]->setNumber(2);
	}
}
void HelloWorld::scoreAddUp(ScoreBroad* broad, int number)
{
	int score = broad->getScore();
	broad->setScore(score + number);
}
void HelloWorld::refreshBroad(int x)
{
	if (2 * x == demo)
	{
		demo = 4 * x;
		broad1->setScore(demo);
	}
	score += x;
	if (score > record)
	{
		record = score;
		UserDefault::sharedUserDefault()->setIntegerForKey("record", record);
		broad2->setScore(record);
	}
	broad3->setScore(score);
}
bool HelloWorld::doLeft()
{
	CCLOG("LEFT");

	bool isdo = false;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 0; x < 4; x++)
		{
			for (int xright = x + 1; xright < 4; xright++)
			{
				if (card[xright][y]->getNumber()>0)
				{
					if (card[x][y]->getNumber() <= 0)
					{
						card[x][y]->setNumber(card[xright][y]->getNumber());
						card[xright][y]->setNumber(0);
						x--;
						isdo = true;
					}
					else if (card[x][y]->getNumber() == card[xright][y]->getNumber())
					{
						refreshBroad(card[x][y]->getNumber());
						card[x][y]->setNumber(card[x][y]->getNumber() * 2);
						card[xright][y]->setNumber(0);
						isdo = true;
					}
					break;
				}
			}
		}
	}
	return isdo;
}
bool HelloWorld::doRight()
{
	CCLOG("RIGHT");

	bool isdo = false;
	for (int y = 0; y < 4; y++)
	{
		for (int x = 3; x >= 0; x--)
		{
			for (int xleft = x - 1; xleft >= 0; xleft--)
			{
				if (card[xleft][y]->getNumber()>0)
				{
					if (card[x][y]->getNumber() <= 0)
					{
						card[x][y]->setNumber(card[xleft][y]->getNumber());
						card[xleft][y]->setNumber(0);
						x++;
						isdo = true;
					}
					else if (card[x][y]->getNumber() == card[xleft][y]->getNumber())
					{
						refreshBroad(card[x][y]->getNumber());
						card[x][y]->setNumber(card[xleft][y]->getNumber() * 2);
						card[xleft][y]->setNumber(0);
						isdo = true;
					}
					break;
				}
			}
		}
	}
	return isdo;
}
bool HelloWorld::doUp()
{
	CCLOG("UP");

	bool isdo = false;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 3; y >= 0; y--)
		{
			for (int ydown = y - 1; ydown >= 0; ydown--)
			{
				if (card[x][ydown]->getNumber()>0)
				{
					if (card[x][y]->getNumber() <= 0)
					{
						card[x][y]->setNumber(card[x][ydown]->getNumber());
						card[x][ydown]->setNumber(0);
						y++;
						isdo = true;
					}
					else if (card[x][y]->getNumber() == card[x][ydown]->getNumber())
					{
						refreshBroad(card[x][y]->getNumber());
						card[x][y]->setNumber(card[x][ydown]->getNumber() * 2);
						card[x][ydown]->setNumber(0);
						isdo = true;
					}
					break;
				}
			}
		}
	}
	return isdo;
}
bool HelloWorld::doDown()
{
	CCLOG("DOWN");

	bool isdo = false;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int yup = y + 1; yup < 4; yup++)
			{
				if (card[x][yup]->getNumber()>0)
				{
					if (card[x][y]->getNumber() <= 0)
					{
						card[x][y]->setNumber(card[x][yup]->getNumber());
						card[x][yup]->setNumber(0);
						y--;
						isdo = true;
					}
					else if (card[x][y]->getNumber() == card[x][yup]->getNumber())
					{
						refreshBroad(card[x][y]->getNumber());
						card[x][y]->setNumber(card[x][yup]->getNumber() * 2);
						card[x][yup]->setNumber(0);
						isdo = true;
					}
					break;
				}
			}
		}
	}
	return isdo;
}