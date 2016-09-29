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

	auto* background = LayerColor::create(Color4B(255, 255, 255, 255));
	addChild(background);
	auto* bar1 = NinePatch::createPatch(200, 500, 60, Vec2(10, 20));
	addChild(bar1);
	auto* bar2 = NinePatch::createPatch(600, 300, 60, Vec2(300, 100));
	addChild(bar2);

    return true;
}
