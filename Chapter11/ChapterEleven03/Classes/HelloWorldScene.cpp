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

	Scale9Sprite* btnNormal = Scale9Sprite::create("button0.png", Rect(0, 0, 200, 200), Rect(50, 50, 100, 100));
	btnNormal->setPreferredSize(Size(800, 550));
	Scale9Sprite* btnPressed = Scale9Sprite::create("button1.png", Rect(0, 0, 200, 200), Rect(50, 50, 100, 100));
	btnPressed->setPreferredSize(Size(800, 550));
	auto* label = Label::create("button", "Courier", 200);
	auto* button = ControlButton::create(label, btnNormal);
	button->setPreferredSize(Size(800, 550));
	button->setBackgroundSpriteForState(btnNormal, Control::State::NORMAL);
	button->setBackgroundSpriteForState(btnPressed, Control::State::HIGH_LIGHTED);
	button->setPosition(480, 320);
	addChild(button);

    return true;
}