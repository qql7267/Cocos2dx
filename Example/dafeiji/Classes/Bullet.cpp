#include "Bullet.h"

Bullet* Bullet::createBullet(Point position)
{
	Bullet* bullet = new Bullet();
	if (bullet&&bullet->init())
	{
		bullet->autorelease();
		bullet->bulletInit(position);
		return bullet;
	}
	CC_SAFE_DELETE(bullet);
	return NULL;
}
bool Bullet::init()
{
	if (!Node::init())
	{
		return false;
	}
	return true;
}
void Bullet::bulletInit(Point position)
{
	isActive = false;
	bullet = Sprite::create("bullet.png");
	bullet->setPosition(position);
	auto* blink = Blink::create(0.3, -1);
	bullet->runAction(blink);
	addChild(bullet);
}
void Bullet::shoot(Point position)
{
	float diretion = 660 - position.y;
	float fullTime = 0.25f;
	float time = diretion * fullTime / 660;
	bullet->setPosition(position);
	auto* moveto = MoveTo::create(time, Vec2(position.x, 660));
	this->bullet->runAction(moveto);
}