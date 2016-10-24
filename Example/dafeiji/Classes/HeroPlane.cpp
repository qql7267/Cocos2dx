#include "HeroPlane.h"

HeroPlane* HeroPlane::createHeroPlane(Point position)
{
	HeroPlane* plane = new HeroPlane();
	if (plane&&plane->init())
	{
		plane->autorelease();
		plane->heroPlaneInit(position);
		return plane;
	}
	CC_SAFE_DELETE(plane);
	return NULL;
}
bool HeroPlane::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
void HeroPlane::heroPlaneInit(Point position)
{
	plane = Sprite::create("plane1.png");
	plane->setScale(0.3f);
	plane->setAnchorPoint(Vec2(0.5f, 0.5f));
	plane->setPosition(position);
	addChild(plane);
	auto* action = actionFly();
	plane->runAction(action);
}
Animate* HeroPlane::actionFly()
{
	auto* animation = Animation::create();
	for (int i = 1; i < 3; i++)
	{
		char s[20] = { 0 };
		sprintf(s, "plane%d.png", i);
		animation->addSpriteFrameWithFile(s);
	}
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.2f);
	auto* action = Animate::create(animation);
	return action;
}
void HeroPlane::planeMove(Point point, Point relative)
{
	this->position = Vec2(point.x - relative.x, point.y - relative.y);
	if (position.x < prePos.x)
	{
		isFlip = false;
		plane->setRotation3D(Vec3(0, 0, -10));
	}
	else
	{
		isFlip = true;
		plane->setRotation3D(Vec3(0, 0, 10));
	}
	plane->setPosition(position);
	plane->setFlipX(isFlip);
	prePos = position;
}