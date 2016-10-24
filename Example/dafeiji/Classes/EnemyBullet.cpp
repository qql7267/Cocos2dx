#include "EnemyBullet.h"

EnemyBullet* EnemyBullet::createBullet()
{
	EnemyBullet* bullet = new EnemyBullet();
	if (bullet&&bullet->init())
	{
		bullet->autorelease();
		bullet->bulletInit();
		return bullet;
	}
	CC_SAFE_DELETE(bullet);
	return NULL;
}
bool EnemyBullet::init()
{
	if (!Node::init())
	{
		return false;
	}
	return true;
}
void EnemyBullet::bulletInit()
{
	isActive = false;
	bullet = Sprite::create("enemybullet.png");
	bullet->setPosition(180, 720);
	bullet->setScale(0.3f);
	addChild(bullet);
}
void EnemyBullet::shoot(Point position)
{
	isActive = true;
	float diretion = position.y + 80;
	float fullTime = 3.0f;
	float time = diretion * fullTime / 800;
	bullet->setPosition(position);
	auto* moveto = MoveTo::create(time, Vec2(position.x, -80));
	this->bullet->runAction(moveto);
}