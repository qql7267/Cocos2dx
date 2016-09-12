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
    
	auto* m_sprite = Sprite::create("sprite.png");
	m_sprite->setPosition(150, 270);
	m_sprite->setScale(0.45f);
	addChild(m_sprite);

	auto* moveto = MoveTo::create(2.5f, Vec2(540, 200));
	auto* scaleto = ScaleTo::create(2.5f, 0.5);
	auto* rotateby = RotateBy::create(2.5f, Vec3(0, 0, 3600));

	auto* action = Spawn::create(moveto, scaleto, rotateby, NULL);

	m_sprite->runAction(action);

    return true;
}
