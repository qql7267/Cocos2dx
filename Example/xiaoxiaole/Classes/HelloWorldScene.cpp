#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

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

	starX = 0;
	starY = 0;
    
	auto* background = Sprite::create("background.png");
	background->setAnchorPoint(Vec2(0, 0));
	background->setPosition(0, 0);
	addChild(background);

	addStar();

	for (int i = 0; i < WIDTH*HEIGHT; i++)
	{
		holder[i] = -1;
	}

	auto* dispatcher = Director::getInstance()->getEventDispatcher();
	auto* listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	scheduleUpdate();

    return true;
}
void HelloWorld::addStar()
{
	srand(unsigned(time(0)));
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			star[x][y] = StarSprite::createStar(rand() % 5 + 1, x, y+20);
			addChild(star[x][y]);
			srand(rand()*rand());
		}
	}
	update(100.0f);
}
bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
	auto position = touch->getLocation();
	if (position.x < 40 * WIDTH&&position.y < 40 * HEIGHT)
	{
		int x = (int)position.x / 40;
		int y = (int)position.y / 40;
		if (star[x][y]->type > 0)
		{
			//star[x][y]->starDelete();
			UDLRDelete(x, y);
			int i = 0;
			while (holder[i] != -1)
			{
				int x = holder[i] % HEIGHT;
				int y = holder[i] / HEIGHT;
				UDLRDelete(x, y);
				i++;
			}
			popStar();
			starDrop();
			starTranslation();
			starMove(0.25f);
			if (isOver())
			{
				CCLOG("aaaa");
				exit(-1);
			}
		}
	}
	return false;
}
void HelloWorld::UDLRDelete(int x, int y)
{
	int type = star[x][y]->type;
	if (type > 0)
	{
		bool isAdd = false;
		if (y + 1 < HEIGHT&&star[x][y + 1]->type == type)
		{
			addToHolder(x, y + 1);
			isAdd = true;
		}
		if (y - 1 > 0&&star[x][y - 1]->type == type)
		{
			addToHolder(x, y - 1);
			isAdd = true;
		}
		if (x + 1 < WIDTH&&star[x + 1][y]->type == type)
		{
			addToHolder(x + 1, y);
			isAdd = true;
		}
		if (x - 1 > 0&&star[x - 1][y]->type == type)
		{
			addToHolder(x - 1, y);
			isAdd = true;
		}
		if (isAdd)
		{
			addToHolder(x, y);
		}
	}
}
void HelloWorld::addToHolder(int x, int y)
{
	int i = 0;
	while (holder[i] != -1)
	{
		if (holder[i] == y*HEIGHT + x)
		{
			break;
		}
		else
		{
			i++;
		}
	}
	holder[i] = y*HEIGHT + x;
}
void HelloWorld::cleanHolder()
{
	int i = 0;
	while (holder[i] != -1)
	{
		holder[i] = -1;
		i++;
	}
}
void HelloWorld::popStar()
{
	int i = 0;
	while (holder[i] != -1)
	{
		int x = holder[i] % HEIGHT;
		int y = holder[i] / HEIGHT;
		CCLOG("%d,%d,%d", i, x, y);
		star[x][y]->starDelete();
		i++;
	}
	cleanHolder();
}
void HelloWorld::starDrop()
{
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 1; y < HEIGHT; y++)
		{
			for (int i = 0; i < y; i++)
			{
				if (star[x][i]->type == 0)
				{
					auto* temp = star[x][i];
					star[x][i] = star[x][y];
					star[x][y] = temp;
				}
			}
		}
	}
}
//void HelloWorld::starTranslation()  //ÓÒ²àÍù×óÌî¿Ó
//{
//	for (int x = 1; x < WIDTH; x++)
//	{
//		for (int y = 0; y < HEIGHT; y++)
//		{
//			for (int i = 0; i < x; i++)
//			{
//				if (star[i][y]->type == 0)
//				{
//					auto* temp = star[i][y];
//					star[i][y] = star[x][y];
//					star[x][y] = temp;
//				}
//			}
//		}
//	}
//}
void HelloWorld::starTranslation() //ÕûÁÐÒÆ¶¯
{
	for (int x = 0; x < WIDTH - 1; x++)
	{
		if (star[x][0]->type == 0)
		{
			for (int y = 0; y < HEIGHT; y++)
			{
				auto* temp = star[x + 1][y];
				star[x + 1][y] = star[x][y];
				star[x][y] = temp;
			}
		}
	}
}
void HelloWorld::starMove(float dt)
{
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			star[x][y]->moveTo(dt, x, y);
		}
	}
}
bool HelloWorld::isOver()
{
	bool over = true;
	for (int x = 0; x < WIDTH; x++)
	{
		if (over)
		{
			for (int y = 0; y < HEIGHT; y++)
			{
				int type = star[x][y]->type;
				if (type > 0)
				{
					if (y + 1 < HEIGHT&&star[x][y + 1]->type == type)
					{
						over = false;
						break;
					}
					if (y - 1 > 0 && star[x][y - 1]->type == type)
					{
						over = false;
						break;
					}
					if (x + 1 < WIDTH&&star[x + 1][y]->type == type)
					{
						over = false;
						break;
					}
					if (x - 1 > 0 && star[x - 1][y]->type == type)
					{
						over = false;
						break;
					}
				}
			}
		}
		else
		{
			break;
		}
	}
	return over;
}
void HelloWorld::starStart()
{
	
}
void HelloWorld::update(float dt)
{
	if (starX < WIDTH&&starY < HEIGHT)
	{
		star[starX][starY]->moveTo(0.6f, starX, starY);
		starX++;
	}
	else if (starY < HEIGHT)
	{
		starX = 0;
		starY++;
	}
	else
	{
		unscheduleUpdate();
	}
}