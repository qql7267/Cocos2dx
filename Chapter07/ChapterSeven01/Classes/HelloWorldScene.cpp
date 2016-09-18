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
	if (!Layer::init())
	{
		return false;
	}

	image = new Image();
	image->initWithImageFile("background1.png");
	background[0] = Sprite::create("background2.jpg");
	background[0]->setAnchorPoint(Vec2(0, 0));
	background[0]->setPosition(-600,-400);
	addChild(background[0]);
	background[1] = Sprite::create("background3.png");
	background[1]->setOpacity(150);
	background[1]->setAnchorPoint(Vec2(0, 0));
	background[1]->setPosition(-600, -400);
	addChild(background[1], 10);

	hero = Hero::createHeroSprite(Vec2(320, 180), 1, "stand");
	addChild(hero);

	rocker = HRocker::createHRocker("rocker.png", "rockerBG.png", ccp(150, 150));
	addChild(rocker, 100);
	rocker->startRocker(true);

	scheduleUpdate();
	return true;
}
void HelloWorld::update(float dt)
{
	if (rocker->isCanMove == true)
	{
		if (hero->isRun == false)
		{
			hero->isRun = true;
			hero->direction = rocker->direction;
			hero->setAction(hero->direction, "run", 8);
		}
		else if (hero->direction != rocker->direction)
		{
			hero->direction = rocker->direction;
			hero->setAction(hero->direction, "run", 8);
		}
		float r = sqrt((rocker->dx*rocker->dx) + (rocker->dy*rocker->dy));
		float x = rocker->dx / r;
		float y = rocker->dy / r;
		Point position = background[1]->getPosition();
		auto pix = 320 - (int)background[1]->getPositionX();
		auto piy = 180 - (int)background[1]->getPositionY();
		CCLOG("%d, %d", pix, piy);
		if (x > 0)
		{
			pix -= 3;
		}
		else
		{
			pix += 3;
		}
		if (y > 0)
		{
			piy += 3;
		}
		else
		{
			piy -= 3;
		}
		if (getColor(pix, piy).a != 0)
		{
			background[0]->setPosition(position.x - x, position.y - y);
			background[1]->setPosition(position.x - x, position.y - y);
		}
	}
	else if (hero->isRun == true && rocker->isCanMove == false)
	{
		hero->isRun = false;
		hero->setAction(hero->direction, "stand", 7);
	}
}
Color4B HelloWorld::getColor(int x, int y)
{
	ccColor4B c = { 0, 0, 0, 0 };
	y = (image->getHeight() - y);
	int width = image->getWidth();
	unsigned char* data_ = image->getData();
	unsigned int* pixel = (unsigned int*)data_;

	pixel = pixel + (y * width) + x;
	c.a = (*pixel >> 24) & 0xff;
	float scale = (c.a + 1.0f) / 256;
	c.r = *pixel & 0xff;
	c.r = c.r / scale;
	c.g = (*pixel >> 8) & 0xff;
	c.g = c.g / scale;
	c.b = (*pixel >> 16) & 0xff;
	c.b = c.b / scale;
	CCLOG("%d,%d==%d,%d,%d,%d", x, y, c.r, c.g, c.b, c.a);
	return c;
}