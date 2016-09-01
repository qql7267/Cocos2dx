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

	auto *layer1 = Layer::create();
	auto *pBackground = Sprite::create("background.png");
	pBackground->setPosition(180, 320);
	layer1->addChild(pBackground);

	auto *layer2 = Layer::create();
	auto *pPlane = Sprite::create("plane.png");
	pPlane->setScale(0.5f);
	pPlane->setPosition(180, 80);
	layer2->addChild(pPlane);

	auto *layer3 = Layer::create();
	auto *number = LabelTTF::create("13400", "Arial", 32);
	number->setPosition(300, 600);
	layer3->addChild(number);

	this->addChild(layer1);
	this->addChild(layer2);
	this->addChild(layer3);

	return true;
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}
