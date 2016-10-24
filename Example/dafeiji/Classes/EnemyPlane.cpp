#include "EnemyPlane.h"

EnemyPlane* EnemyPlane::createEnemy()
{
	EnemyPlane* enemy = new EnemyPlane();
	if (enemy && enemy->init())
	{
		enemy->autorelease();
		enemy->EnemyInit();
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return NULL;
}
bool EnemyPlane::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
void EnemyPlane::EnemyInit()
{
	this->type = 0;
	enemy = Sprite::create("enemy1.png");
	enemy->setPosition(Vec2(-100, -100));
	addChild(enemy);
}
void EnemyPlane::start(int type, int positionX)
{
	this->type = type;
	if (type == 1)
	{
		auto frame = SpriteFrame::create("enemy1.png", Rect(0, 0, 256, 256));
		enemy->setDisplayFrame(frame);
		enemy->setScale(0.5f);
		blood = 25;
	}
	else if (type == 2)
	{
		auto frame = SpriteFrame::create("enemy2.png", Rect(0, 0, 256, 256));
		enemy->setDisplayFrame(frame);
		enemy->setScale(0.25f);
		blood = 10;
	}
	else if (type == 3)
	{
		auto frame = SpriteFrame::create("enemy3.png", Rect(0, 0, 220, 220));
		enemy->setDisplayFrame(frame);
		enemy->setScale(0.1f);
		blood = 5;
	}
	enemy->setPosition(positionX, START_HEIGHT);
	auto* moveto = MoveTo::create((float)18 / type, Vec2(positionX, END_HEIGHT));
	auto* rotateto = RotateTo::create((float)18 / type, Vec3(0, 0, 1800));
	auto* spawn = Spawn::create(moveto, rotateto, NULL);
	enemy->runAction(spawn);
}
void EnemyPlane::enemyDestory()
{
	if (blood > 0)
	{
		blood--;
	}
	else
	{
		enemy->setPosition(-200, 0);
		type = 0;
	}
}