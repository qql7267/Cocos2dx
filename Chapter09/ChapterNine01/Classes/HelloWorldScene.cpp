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

	ball = Sprite::create("ball.png");
	ball->setPosition(480, 320);
	addChild(ball);
	b2Vec2 gravity;
	gravity.Set(0.0f, -2.0f);
	world = new b2World(gravity);
	world->SetAllowSleeping(true);
	world->SetContinuousPhysics(true);
	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(0, 0);
	b2Body* groundBody = world->CreateBody(&groundBodyDef);
	groundBody->SetType(b2_staticBody);
	b2EdgeShape groundBox;
	groundBox.Set(b2Vec2(0, 0), b2Vec2(960, 0));
	groundBody->CreateFixture(&groundBox, 0);
	groundBox.Set(b2Vec2(0, 640), b2Vec2(960, 640));
	groundBody->CreateFixture(&groundBox, 0);
	groundBox.Set(b2Vec2(0, 640), b2Vec2(0, 0));
	groundBody->CreateFixture(&groundBox, 0);
	groundBox.Set(b2Vec2(960, 640), b2Vec2(960, 0));
	groundBody->CreateFixture(&groundBox, 0);
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(480, 320);
	b2Body* ballbody = world->CreateBody(&bodyDef);
	ballbody->SetUserData(ball);
	ballbody->SetActive(true);
	b2PolygonShape dynamicBox;
	dynamicBox.SetAsBox(0.5f, 0.5f);
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &dynamicBox;
	fixtureDef.density = 10.0f;
	fixtureDef.restitution = 0.9f;
	fixtureDef.friction = 0.3f;
	ballbody->CreateFixture(&fixtureDef);
	this->scheduleUpdate();

    return true;
}
void HelloWorld::update(float dt)
{
	int velocityIterations = 8;
	int positionIterations = 1;
	world->Step(0.2f, velocityIterations, positionIterations);
	for (b2Body* b = world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
		{
			Sprite* sprite = (CCSprite*)b->GetUserData();
			if (sprite != NULL)
			{
				b2Vec2 bodyPos = b->GetPosition();
				Point pos = ccp(bodyPos.x, bodyPos.y);
				float32 roration = -1 * CC_RADIANS_TO_DEGREES(b->GetAngle());
				sprite->setPosition(pos);
				sprite->setRotation(roration);
			}
		}
	}
}
