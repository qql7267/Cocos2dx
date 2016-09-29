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

	auto* switchBG = Sprite::create("background.png");
	auto* switchOn = Sprite::create("on.png");
	auto* switchOff = Sprite::create("off.png");
	auto* switchBar = Sprite::create("button.png");
	auto* on = Label::create("on", "Courier", 36);
	auto* off = Label::create("off", "Courier", 36);

	auto* controlSwitch = ControlSwitch::create(switchBG, switchOn, switchOff, switchBar, on, off);		
	controlSwitch->setPosition(480, 320);
	addChild(controlSwitch);

	controlSwitch->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::change), Control::EventType::VALUE_CHANGED);

    return true;
}
void HelloWorld::change(Ref* pSender, Control::EventType event)
{
	if (event == Control::EventType::VALUE_CHANGED)
	{
		auto* s = (ControlSwitch*)pSender;
		if (s->isOn())
		{
			CCLOG("the switch is on!");
		}
		else
		{
			CCLOG("this switch is off!");
		}
	}
}
