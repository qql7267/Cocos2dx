#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;
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

	auto* slider = ControlSlider::create("background.png", "progress.png", "bar.png");
	slider->setPosition(480, 320);
	addChild(slider);
	slider->setMaximumValue(100);
	slider->setMinimumValue(0);
	slider->setValue(30);

    return true;
}
