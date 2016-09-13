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
    
	Size visableSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto* background = Sprite::create("background.png");
	background->setPosition(visableSize.width / 2, visableSize.height / 2);
//	background->setScale(1.5f);
	background->setScaleX(1.5f);
	background->setScaleY(1.77f);
	addChild(background);

	for (int i = 0; i < 5; i++)
	{
		char imageName[15] = { 0 };
		sprintf(imageName, "mycard0%d.png", i);
		myCard[i] = Sprite::create(imageName);
		myCard[i]->setScale(0.39f);
		myCard[i]->setPosition(visableSize.width*(i + 1) / 6, visableSize.height / 2);
		this->addChild(myCard[i]);
	}

	auto myListener = EventListenerTouchOneByOne::create();
	myListener->setSwallowTouches(true);
	myListener->onTouchBegan = [=](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		Point locationInNode = target->convertToNodeSpace(touch->getLocation());
		Size s = target->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);
		if (rect.containsPoint(locationInNode))
		{
			log("sprite began... x = %f,y = %f", locationInNode.x, locationInNode.y);
			target->setOpacity(180);
			return true;
		}
		return false;
	};
	myListener->onTouchMoved = [](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		log("sprite move... x = %d,y = %f", touch->getLocation().x, touch->getLocation().y);
		target->setPosition(target->getPosition() + touch->getDelta());
	};
	myListener->onTouchEnded = [](Touch* touch, Event* event)
	{
		auto target = static_cast<Sprite*>(event->getCurrentTarget());
		target->setOpacity(255);
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myListener, myCard[0]);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myListener->clone(), myCard[1]);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myListener->clone(), myCard[2]);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myListener->clone(), myCard[3]);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(myListener->clone(), myCard[4]);
	
    return true;
}
