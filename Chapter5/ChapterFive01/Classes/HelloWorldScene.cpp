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

	Sprite* m_sprite[5];
	for (int i = 0; i < 5; i++)
	{
		m_sprite[i] = Sprite::create("sprite.png");
		m_sprite[i]->setScale(0.45f);
		m_sprite[i]->setPosition(157 * (i + 1), 80);

		addChild(m_sprite[i]);
	}
	auto* moveto = MoveTo::create(1.2f, Vec2(300,450));
	m_sprite[0]->runAction(moveto);

	auto* moveby = MoveBy::create(1.2f, Vec2(310, 280));
	m_sprite[1]->runAction(moveby);

	auto* scaleby = ScaleBy::create(1.2f, 2.0f, 0.5f);
	m_sprite[2]->runAction(scaleby);

	auto* blink = Blink::create(1.2f, 4);
	m_sprite[3]->runAction(blink);

	ccBezierConfig bezier;
	bezier.controlPoint_1 = Vec2(-100, 0);
	bezier.controlPoint_2 = Vec2(100, 80);
	bezier.endPosition = Vec2(0, 160);

	auto* bezierby = BezierBy::create(2.0f, bezier);
	m_sprite[4]->runAction(bezierby);

    return true;
}
