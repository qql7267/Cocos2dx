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

	auto* controler = ControlPotentiometer::create("background.png", "progress.png", "button.png");
	controler->setPosition(480, 320);
	controler->setScale(1.05f);
	addChild(controler);
	controler->setMaximumValue(100);
	controler->setMinimumValue(0);
	controler->setValue(30);

	controler->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::change), Control::EventType::VALUE_CHANGED);

    return true;
}
void HelloWorld::change(Object* pSender, Control::EventType event)
{
	auto* controler = (ControlPotentiometer*)pSender;
	float num = controler->getValue();
	CCLOG("the value of controler is:%f", num);
}