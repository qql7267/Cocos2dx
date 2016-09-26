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
#define PTM_RATIO 32
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
	b2Vec2 gravity = b2Vec2(0.0f, -0.5f);
	_world = new b2World(gravity);
	_world->SetAllowSleeping(true);
	_world->SetContinuousPhysics(true);
	b2BodyDef groundBodyDef;
	b2Body* groundBody = _world->CreateBody(&groundBodyDef);
	groundBody->SetType(b2_staticBody);
	b2EdgeShape groundBox;
	b2FixtureDef boxShapeDef;
	groundBox.Set(b2Vec2(0, 0), b2Vec2(960 / PTM_RATIO, 0));
	groundBody->CreateFixture(&groundBox, 0);
	groundBox.Set(b2Vec2(0, 640 / PTM_RATIO), b2Vec2(960 / PTM_RATIO, 640 / PTM_RATIO));
	groundBody->CreateFixture(&groundBox, 0);
	groundBox.Set(b2Vec2(0, 0), b2Vec2(0, 640 / PTM_RATIO));
	groundBody->CreateFixture(&groundBox, 0);
	groundBox.Set(b2Vec2(960 / PTM_RATIO, 0), b2Vec2(960 / PTM_RATIO, 640 / PTM_RATIO));
	groundBody->CreateFixture(&groundBox, 0);
	boxShapeDef.shape = &groundBox;
	b2BodyDef ballBodyDef;
	ballBodyDef.type = b2_dynamicBody;
	ballBodyDef.position.Set(480 / PTM_RATIO, 300 / PTM_RATIO);
	ballBodyDef.userData = ball;
	b2CircleShape circle;
	circle.m_radius = 32.0 / PTM_RATIO;
	_body = _world->CreateBody(&ballBodyDef);
	b2FixtureDef ballShapeDef;
	ballShapeDef.shape = &circle;
	ballShapeDef.density = 1.0f;
	ballShapeDef.friction = 0.1;
	ballShapeDef.restitution = 0.9f;
	_body->CreateFixture(&ballShapeDef);
	auto* dispatcher = Director::getInstance()->getEventDispatcher();
	auto* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	listener->setSwallowTouches(true);
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	this->scheduleUpdate();
    return true;
}
void HelloWorld::update(float dt)
{
	int velocityIterations = 8;
	int positionIterations = 1;
	_world->Step(0.2f, velocityIterations, positionIterations);
	for (b2Body* b = _world->GetBodyList(); b; b = b->GetNext())
	{
		if (b->GetUserData() != NULL)
		{
			Sprite* sprite = (CCSprite*)b->GetUserData();
			if (sprite != NULL)
			{
				b2Vec2 bodyPos = b->GetPosition();
				Point pos = ccp(bodyPos.x*PTM_RATIO, bodyPos.y*PTM_RATIO);
				float rotation = -1 * CC_RADIANS_TO_DEGREES(b->GetAngle());
				sprite->setPosition(pos);
				sprite->setRotation(rotation);
			}
		}
	}
}
bool HelloWorld::onTouchBegan(Touch* touch, Event* event)
{
	prePos = touch->getLocation();
	return true;
}
void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
	auto position = touch->getLocation();
	float dx = (position.x - prePos.x) / 16;
	float dy = (position.y - prePos.y) / 16;
	b2Vec2 v = _body->GetLinearVelocity();
	v.x += dx;
	v.y += dy;
	_body->SetLinearVelocity(v);
}