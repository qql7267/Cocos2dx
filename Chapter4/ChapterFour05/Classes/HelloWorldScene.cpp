#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "HRocker.h"
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
	background->setPosition(480, 320);
	background->setScale(1.5f);
	addChild(background);
    
	HRocker* rocker = HRocker::createHRocker("rocker.png", "rockerBG.png",ccp(200,200));
	addChild(rocker);
	rocker->startRocker(true);

    return true;
}
