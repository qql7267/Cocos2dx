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
    
	//爆炸粒子效果
	auto* explosion = ParticleExplosion::create();
	explosion->setPosition(120, 120);
	addChild(explosion);

	//火焰粒子效果
	auto* fire = ParticleFire::create();
	fire->setPosition(360, 120);
//	fire->setAngle(45);
//	fire->setEndSize(200);
	addChild(fire);

	//烟花粒子效果
	auto* fireworks = ParticleFireworks::create();
	fireworks->setPosition(600, 120);
	addChild(fireworks);

	//花粒子效果
	auto* flower = ParticleFlower::create();
	flower->setPosition(840, 120);
	addChild(flower);

	//星系粒子效果
	auto* galaxy = ParticleGalaxy::create();
	galaxy->setPosition(240, 320);
	addChild(galaxy);

	//流星粒子效果
	auto* meteor = ParticleMeteor::create();
	meteor->setPosition(480, 320);
	addChild(meteor);

	//漩涡粒子效果
	auto* spiral = ParticleSpiral::create();
	spiral->setPosition(720, 360);
	addChild(spiral);

	//雪粒子效果
	auto* snow = ParticleSnow::create();
	snow->setPosition(120, 520);
	addChild(snow);

	//烟粒子效果
	auto* smoke = ParticleSmoke::create();
	smoke->setPosition(360, 520);
	addChild(smoke);

	//太阳粒子效果
	auto* sun = ParticleSun::create();
	sun->setPosition(600, 520);
	addChild(sun);

	//雨粒子效果
	auto* rain = ParticleRain::create();
	rain->setPosition(840, 520);
	addChild(rain);

    return true;
}
