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

#define MAP_SIZE 1320
// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	size = Director::getInstance()->getVisibleSize();
	map = TMXTiledMap::create("map.tmx");
	addChild(map);
	meta = map->layerNamed("meta");
	meta->setVisible(false);
	sprite = Sprite::create("sprite.png");
	map->addChild(sprite, 10);
	sprite->setPosition(16.5f, 16.5f);
	auto* pLeft = MenuItemImage::create("left.png", "left1.png", this, menu_selector(HelloWorld::left));
	auto* left = Menu::create(pLeft, NULL);
	left->setPosition(620, 80);
	addChild(left);
	auto* pUp = MenuItemImage::create("up.png", "up1.png", this, menu_selector(HelloWorld::up));
	auto* up = Menu::create(pUp, NULL);
	up->setPosition(670, 130);
	addChild(up);
	auto* pRight = MenuItemImage::create("right.png", "right1.png", this, menu_selector(HelloWorld::right));
	auto* right = Menu::create(pRight, NULL);
	right->setPosition(720, 80);
	addChild(right);
	auto* pDown = MenuItemImage::create("down.png", "down1.png", this, menu_selector(HelloWorld::down));
	auto* down = Menu::create(pDown, NULL);
	down->setPosition(670, 30);
	addChild(down);
	return true;
}
void HelloWorld::up(cocos2d::Object* pSender)
{
	float y = sprite->getPositionY();
	if (y + 16.5 < MAP_SIZE&&isCanReach(sprite->getPositionX(), y + 33))
	{
		sprite->setPositionY(y + 33);
		if ((y + map->getPositionY() > size.height / 2) && ((MAP_SIZE - y + 33) > size.height / 2))
		{
			map->setPositionY(map->getPositionY() - 33);
		}
	}
}
void HelloWorld::right(cocos2d::Object* pSender)
{
	float x = sprite->getPositionX();
	if (x + 16.5 < MAP_SIZE&&isCanReach(x + 33, sprite->getPositionY()))
	{
		sprite->setPositionX(x + 33);
		if ((x + map->getPositionX() > size.width / 2) && ((MAP_SIZE - x + 33) > size.width / 2))
		{
			map->setPositionX(map->getPositionX() - 33);
		}
	}
}
void HelloWorld::left(cocos2d::Object* pSender)
{
	float x = sprite->getPositionX();
	if (x > 16.5&&isCanReach(x - 33, sprite->getPositionY()))
	{
		sprite->setPositionX(x - 33);
		if ((x + map->getPositionX() < size.width / 2) && map->getPositionX() != 0)
		{
			map->setPositionX(map->getPositionX() + 33);
		}
	}
}
void HelloWorld::down(cocos2d::Object* pSender)
{
	float y = sprite->getPositionY();
	if (y > 16.5&&isCanReach(sprite->getPositionX(), y - 33))
	{
		sprite->setPositionY(y - 33);
		if ((y + map->getPositionY() < size.height / 2) && map->getPositionY() != 0)
		{
			map->setPositionY(map->getPositionY() + 33);
		}
	}
}
bool HelloWorld::isCanReach(float x, float y)
{
	int mapX = (int)((x - 16.5) / 33);
	int mapY = (int)(39 - (y - 16.5) / 33);
	int tileGid = meta->tileGIDAt(Vec2(mapX, mapY));
	if (tileGid == 49)
		return true;
	else
		return false;
}
