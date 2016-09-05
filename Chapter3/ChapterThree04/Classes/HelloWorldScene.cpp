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
    
	Size size = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto* background = Sprite::create("background.jpg");
	background->setPosition(size.width, size.height);
	background->setScale(1.0f);
	addChild(background, 0);

	auto* button1 = Sprite::create("button1.png");
	button1->setPosition(550, size.height / 2);
	button1->setScale(0.6f);
	addChild(button1, 1);

	auto* pButton2 = MenuItemImage::create("button1.png", "button2.png", this, menu_selector(HelloWorld::menu));

	auto* button2 = Menu::create(pButton2, NULL);
	button2->setAnchorPoint(Vec2(0, 0));
	button2->setPosition(550, size.height / 2 - 60);
	button2->setScale(0.6f);
	addChild(button2, 1);

	auto* pButton3 = MenuItemImage::create("button1.png", "button2.png", this, menu_selector(HelloWorld::menu));
	auto* label3 = LabelTTF::create("start", "Arail", 36);
	auto* pLabel3 = MenuItemLabel::create(label3, this, menu_selector(HelloWorld::menu));

	auto* button3 = Menu::create(pButton3, pLabel3, NULL);
	button3->setAnchorPoint(Vec2(0, 0));
	button3->setPosition(550, size.height / 2 - 120);
	button3->setScale(0.6f);
	addChild(button3, 1);

	auto* renwu = Sprite::create("renwu.png");
	renwu->setPosition(0, 0);
	renwu->setAnchorPoint(Vec2(0, 0));
	renwu->setScale(0.5f);
	addChild(renwu, 2);

	return true;
}
void HelloWorld::menu(cocos2d::Object* pSender)
{
	CCLOG("button pressed");
}
