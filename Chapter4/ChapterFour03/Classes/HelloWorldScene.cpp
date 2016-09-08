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
    
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	this->mouse = Sprite::create("mouse.png");
	this->mouse->setScale(0.3f);
	this->addChild(mouse);
	auto myKeyListener = EventListenerKeyboard::create();
	myKeyListener->onKeyPressed = [](EventKeyboard::KeyCode keycode, cocos2d::Event *event)
	{
		CCLOG("Key is pressed,keycode is %d", keycode);
	};
	myKeyListener->onKeyReleased = [](EventKeyboard::KeyCode keycode, cocos2d::Event *event)
	{
		CCLOG("Key is released,keycode is %d", keycode);
	};
	auto myMouseListener = EventListenerMouse::create();
	myMouseListener->onMouseMove = [=](Event *event)
	{
		EventMouse* e = (EventMouse*)event;
		this->mouse->setPosition(e->getCursorX(), e->getCursorY());
	};
	myMouseListener->onMouseDown = [=](Event *event)
	{
		this->mouse->setScale(0.2f);
	};
	myMouseListener->onMouseUp = [=](Event *event)
	{
		this->mouse->setScale(0.3f);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myKeyListener, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myMouseListener, this);
	
    return true;
}
