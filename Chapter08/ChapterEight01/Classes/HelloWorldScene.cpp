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
    
	auto* m_emitter = new ParticleSystemQuad();
	m_emitter->initWithTotalParticles(900);
	m_emitter->setTexture(TextureCache::sharedTextureCache()->addImage("snow1.png"));
	m_emitter->setDuration(-1);
	m_emitter->setGravity(Point(0, -100));
	m_emitter->setAngle(90);
	m_emitter->setAngleVar(360);
	m_emitter->setRadialAccel(50);
	m_emitter->setTangentialAccelVar(0);
	m_emitter->setTangentialAccel(30);
	m_emitter->setTangentialAccelVar(0);
	m_emitter->setPosition(Point(960, 640));
	m_emitter->setPosVar(Point(960, 0));
	m_emitter->setLife(4);
	m_emitter->setLifeVar(2);
	m_emitter->setStartSpin(30);
	m_emitter->setStartSpinVar(60);
	m_emitter->setEndSpin(60);
	m_emitter->setEndSpinVar(60);
	ccColor4F cc;
	cc.a = 1.0f;
	cc.b = 255.0f;
	cc.g = 255.0f;
	cc.r = 255.0f;
	ccColor4F cc2;
	cc2.a = 0;
	cc2.b = 0;
	cc2.g = 0;
	cc2.r = 0;
	m_emitter->setStartColor(cc);
	m_emitter->setStartColorVar(cc2);
	m_emitter->setEndColor(cc);
	m_emitter->setEndColorVar(cc2);
	m_emitter->setStartSize(30);
	m_emitter->setStartSizeVar(0);
	m_emitter->setEndSize(20.0f);
	m_emitter->setEndSizeVar(0);
	m_emitter->setEmissionRate(100);
	addChild(m_emitter);

    return true;
}
