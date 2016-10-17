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
    

	for (int i = 0; i < 6; i++)
	{
		sprite[i] = Sprite::create(String::createWithFormat("sprite%d.png", i)->getCString());
		sprite[i]->setOpacity(0);
		addChild(sprite[i], 2);
		sprite[i]->setPosition(480, 320);
	}
	sprite[0]->setOpacity(255);
	tag = 0;

    auto* rootNode = CSLoader::createNode("MainScene.csb");
	rootNode->setAnchorPoint(Vec2(0,0));
	rootNode->setScaleX(960 / rootNode->getContentSize().width);
	rootNode->setScaleY(640 / rootNode->getContentSize().height);
    addChild(rootNode);

	Button* left = (Button*)rootNode->getChildByName("Button_1");
	left->addTouchEventListener(this, toucheventselector(HelloWorld::left));

	Button* right = (Button*)rootNode->getChildByName("Button_2");
	right->addTouchEventListener(this, toucheventselector(HelloWorld::right));

	return true;
}
void HelloWorld::left(cocos2d::Ref* pSender, TouchEventType type)
{
	if (type == ui::TouchEventType::TOUCH_EVENT_BEGAN)
	{
		CCLOG("left");
		sprite[(tag + 1) % 6]->setPosition(780, 320);
		sprite[(tag + 1) % 6]->setOpacity(0);
		sprite[(tag + 1) % 6]->setScale(0.3f);
		auto moveto1 = MoveTo::create(0.3, Vec2(180, 320));
		auto scaleto1 = ScaleTo::create(0.3, 0.2f);
		auto fadeto1 = FadeTo::create(0.3, 0);
		auto spawn1 = Spawn::create(moveto1, scaleto1, fadeto1, NULL);
		sprite[tag]->runAction(spawn1);
		auto moveto2 = MoveTo::create(0.3, Vec2(480, 320));
		auto scaleto2 = ScaleTo::create(0.3, 1);
		auto fadeto2 = FadeTo::create(0.3, 255);
		auto spawn2 = Spawn::create(moveto2, scaleto2, fadeto2, NULL);
		sprite[(tag + 1) % 6]->runAction(spawn2);
		tag = (tag + 1) % 6;
	}
}
void HelloWorld::right(cocos2d::Ref* pSender, TouchEventType type)
{
	if (type == ui::TouchEventType::TOUCH_EVENT_BEGAN)
	{
		CCLOG("right");
		sprite[(tag + 7) % 6]->setPosition(180, 320);
		sprite[(tag + 7) % 6]->setOpacity(0);
		sprite[(tag + 7) % 6]->setScale(0.3f);
		auto moveto1 = MoveTo::create(0.3, Vec2(780, 320));
		auto scaleto1 = ScaleTo::create(0.3, 0.2f);
		auto fadeto1 = FadeTo::create(0.3, 0);
		auto spawn1 = Spawn::create(moveto1, scaleto1, fadeto1, NULL);
		sprite[tag]->runAction(spawn1);
		auto moveto2 = MoveTo::create(0.3, Vec2(480, 320));
		auto scaleto2 = ScaleTo::create(0.3, 1);
		auto fadeto2 = FadeTo::create(0.3, 255);
		auto spawn2 = Spawn::create(moveto2, scaleto2, fadeto2, NULL);
		sprite[(tag + 1) % 6]->runAction(spawn2);
		tag = (tag + 7) % 6;
	}
}