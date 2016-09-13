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
    
	i = 5;
	scheduleUpdate();
	CCLOG("update srtartted!");

    return true;
}
void HelloWorld::update(float dt)
{
	if (i > 0)
	{
		CCLOG("now the number i is %d", i);
		i--;
	}
	else
	{
		unscheduleUpdate();
		CCLOG("update ended!");
		schedule(schedule_selector(HelloWorld::myupdate), 0.2f);
		CCLOG("myupdate startted!");
	}
}
void HelloWorld::myupdate(float dt)
{
	if (i < 5)
	{
		i++;
		CCLOG("new the number i is %d", i);
	}
	else
	{
		unschedule(schedule_selector(HelloWorld::myupdate));
		CCLOG("myupdate ended!");
	}
}