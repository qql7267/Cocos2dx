#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#include <ctime>

USING_NS_CC;

using namespace cocostudio::timeline;

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

	auto* background = Sprite::create("background.png");
	background->setAnchorPoint(Vec2(0, 0));
	background->setPosition(0, 0);
	addChild(background);

	score = 0;
	scoreLabel = Label::create(String::createWithFormat("score:%d", score)->getCString(), "Arail.ttf", 16);
	scoreLabel->setAnchorPoint(Vec2(0, 0));
	scoreLabel->setPosition(510, 230);
	addChild(scoreLabel);

	timeLabel = Label::create(String::createWithFormat("time:%d", time)->getCString(), "Arial.ttf", 16);
	timeLabel->setAnchorPoint(Vec2(0, 0));
	timeLabel->setPosition(510, 200);
	addChild(timeLabel); 

	propNum = 10;
	propLabel = Label::create(String::createWithFormat("props:%d", propNum)->getCString(), "Arial.ttf", 16);
	propLabel->setAnchorPoint(Vec2(0, 0));
	propLabel->setPosition(510, 170);
	addChild(propLabel);

	timeOut = false;
	time = FULLTIME;
    
	temp = Vec2(-1, -1);

	int id = UserDefault::sharedUserDefault()->getIntegerForKey("id");
	auto* recMap = TMXTiledMap::create(String::createWithFormat("rec%d.tmx",id)->getCString());
	recMap->setAnchorPoint(Vec2(0, 0));
	recMap->setPosition(0, 0);
	recLayer = recMap->layerNamed("Layer1");
	initBoard();

	propNum = 10;
	auto* pButton = MenuItemImage::create("button1.png", "button2.png",this,menu_selector(HelloWorld::prop));
	auto* button = Menu::create(pButton, NULL);
	button->setAnchorPoint(Vec2(0, 0));
	button->setScale(0.4);
	button->setPosition(540, 130);
	addChild(button);

	bar = CountDownBar::createCounDownBar(Vec2(0, 360), 480);
	addChild(bar);
	scheduleUpdate();

	auto* dispatcher = Director::getInstance()->getEventDispatcher();
	auto* listerner = EventListenerTouchOneByOne::create();

	listerner->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);

	dispatcher->addEventListenerWithSceneGraphPriority(listerner, this);

    return true;
}
void HelloWorld::initBoard()
{
	int k = 0;
	int t_card[WIDTH*HEIGHT] = { 0 };
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			int id = recLayer->tileGIDAt(Vec2(x, y));
			if (id == 2)
			{
				k++;
			}
		}
	}
	srand(unsigned(std::time(0)));
	for (int i = 0; i < k / 2; i++)
	{
		t_card[i] = rand() % 5 + 1;
		t_card[i + k / 2] = t_card[i];
	}
	for (int i = 0; i < k; i++)
	{
		int t_k = rand() % k;
		int t = t_card[i];
		t_card[i] = t_card[t_k];
		t_card[t_k] = t;
	}
	k = 0;
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			int id = recLayer->tileGIDAt(Vec2(x, y));
			if (id == 2)
			{
				card[x][y] = CardSprite::createCardSprite(t_card[k], x, y);
				addChild(card[x][y]);
				k++;
			}
			else
			{
				card[x][y] = CardSprite::createCardSprite(0, x, y);
				addChild(card[x][y]);
			}
		}
	}
}
bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
	Point point = touch->getLocation();
	int x = (int)point.x / SIZE;
	int y = (int)point.y / SIZE;
	
	if (x < WIDTH&&y < HEIGHT)
	{
		if (card[x][y]->type != 0)
		{
			int x1 = (int)temp.x;
			int y1 = (int)temp.y;
			if (x1 != -1 && y1 != -1)
			{
				if (isCanConnection(x, y, x1, y1))
				{
					card[x][y]->cardDelete();
					card[x1][y1]->cardDelete();
					temp = Vec2(-1, -1);
				}
				else
				{
					card[x1][y1]->setOpacity(255);
					temp = Vec2(-1, -1);
				}
			}
			else
			{
				temp = Vec2(x, y);
				card[x][y]->setCascadeOpacityEnabled(true);
				card[x][y]->setOpacity(180);
			}
		}
	}
	return false;
}
bool HelloWorld::noCorner(int x1, int y1, int x2, int y2)
{
	if (x1 == x2)
	{
		int start = y1 < y2 ? y1 : y2;
		int end = y1 > y2 ? y1 : y2;
		for (int i = start + 1; i < end; i++)
		{
			if (card[x1][i]->type != 0)
			{
				return false;
			}
		}
		return true;
	}
	else if (y1 == y2)
	{
		int start = x1 < x2 ? x1 : x2;
		int end = x1 > x2 ? x1 : x2;
		for (int i = start + 1; i < end; i++)
		{
			if (card[i][y1]->type != 0)
			{
				return false;
			}
		}
		return true;
	}
	return false;
}
bool HelloWorld::oneCorner(int x1, int y1, int x2, int y2)
{
	if (!(x1 == x2 || y1 == y2))
	{
		if (card[x1][y2]->type == 0)
		{
			if (noCorner(x1, y1, x1, y2) && noCorner(x2, y2, x1, y2))
			{
				return true;
			}
			return false;
		}
		if (card[x2][y1]->type == 0)
		{
			if (noCorner(x1, y1, x2, y1) && noCorner(x2, y2, x2, y1))
			{
				return true;
			}
			return false;
		}
	}
	return false;
}
bool HelloWorld::twoCorner(int x1, int y1, int x2, int y2)
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (i != x1&&card[i][y1]->type == 0)
		{
			if (noCorner(x1, y1, i, y1) && oneCorner(x2, y2, i, y1))
			{
				return true;
			}
		}
	}
	for (int j = 0; j < HEIGHT; j++)
	{
		if (j != y1&&card[x1][j]->type == 0)
		{
			if (noCorner(x1, y1, x1, j) && oneCorner(x2, y2, x1, j))
			{
				return true;
			}
		}
	}
	return false;
}
bool HelloWorld::isCanConnection(int x1, int y1, int x2, int y2)
{
	if (x1 == x2&&y1 == y2)
	{
		return false;
	}
	if (noCorner(x1, y1, x2, y2))
	{
		return true;
	}
	if (oneCorner(x1, y1, x2, y2))
	{
		return true;
	}
	if (twoCorner(x1, y1, x2, y2))
	{
		return true;
	}
	return false;
}
void HelloWorld::update(float dt)
{
	if (time > 0)
	{
		bar->barUpdate(time, FULLTIME);
		time--;
		timeLabel->setString(String::createWithFormat("time:%.2fs", (float)time / 60)->getCString());
	}
	else
	{
		if (!timeOut)
		{
			timeOut = true;
		}
	}
}
void HelloWorld::prop(Ref* pSender)
{
	if (propNum > 0)
	{
		for (int x1 = 0; x1 < WIDTH; x1++)
		{
			for (int y1 = 0; y1 < HEIGHT; y1++)
			{
				if (card[x1][y1]->type != 0)
				{
					for (int x2 = 0; x2 < WIDTH; x2++)
					{
						for (int y2 = 0; y2 < HEIGHT; y2++)
						{
							if ((!(x1 == x2&&y1 == y2)) && (card[x1][y1]->type == card[x2][y2]->type))
							{
								if (isCanConnection(x1, y1, x2, y2))
								{
									CCLOG("%d,%d:%d,%d", x2, y1, x2, y2);
									card[x1][y1]->card->setCascadeOpacityEnabled(true);
									card[x2][y2]->card->setCascadeOpacityEnabled(true);
									card[x1][y1]->card->setOpacity(80);
									card[x2][y2]->card->setOpacity(80);
									x1 = WIDTH;
									x2 = WIDTH;
									y1 = HEIGHT;
									y2 = HEIGHT;
									propNum--;
									propLabel->setString(String::createWithFormat("props:%d", propNum)->getCString());
								}
							}
						}
					}
				}
			}
		}
		propNum--;
	}
}