#include "hero.h"
#define PI 3.1415926

void Hero::initHeroSprite(int direction, cocos2d::Point position)
{
	this->position = position;
	sprite = Sprite::create("stand11.png");
	sprite->setPosition(position);
	addChild(sprite);
	sprite->runAction(this->createAnimate(direction, "stand", 7));
}
Animate* Hero::createAnimate(int direction, const char* action, int num)
{
	auto* m_frameCache = SpriteFrameCache::getInstance();
	m_frameCache->addSpriteFramesWithFile("hero.plist", "hero.png");
	Vector<SpriteFrame*> frameArray;
	for (int i = 1; i < num; i++)
	{
		auto* frame = m_frameCache->getSpriteFrameByName(String::createWithFormat("%s%d%d.png", action, direction, i)->getCString());
		frameArray.pushBack(frame);
	}
	Animation* animation = Animation::createWithSpriteFrames(frameArray);
	animation->setLoops(-1);
	animation->setDelayPerUnit(0.1f);
	return Animate::create(animation);
}
int Hero::getDirection(cocos2d::Point pos1, cocos2d::Point pos2)
{
	float x = pos2.x - pos1.x;
	float y = pos2.y - pos1.y;
	float r = sqrt(x*x + y*y);

	if (x > 0 && fabs(y / r) < sin(15 * PI / 180))
	{
		CCLOG("RIGHT");
		this->direction = RIGHT;
	}
	else if (x < 0 && fabs(y / r) < sin(15 * PI / 180))
	{
		CCLOG("LEFT");
		this->direction = LEFT;
	}
	else if (y > 0 && fabs(y / r) < sin(15 * PI / 180))
	{
		CCLOG("UP");
		this->direction = UP;
	}
	else if (y < 0 && fabs(y / r) < sin(15 * PI / 180))
	{
		CCLOG("DOWN");
		this->direction = DOWN;
	}
	else if (x > 0 && y>0)
	{
		CCLOG("RIGHT_UP");
		this->direction = RIGHT_UP;
	}
	else if (x > 0 && y < 0)
	{
		CCLOG("RIGHT_DOWN");
		this->direction = RIGHT_DOWN;
	}
	else if (x < 0 && y < 0)
	{
		CCLOG("LEFT_DOWN");
		this->direction = LEFT_DOWN;
	}
	else if (x < 0 && y > 0)
	{
		CCLOG("LEFT_UP");
		this->direction = LEFT_UP;
	}
	return this->direction;
}
float Hero::getDistance(cocos2d::Point pos1, cocos2d::Point pos2)
{
	float x = pos2.x - pos1.x;
	float y = pos2.y - pos1.y;
	return sqrt(x*x + y*y);
}
void Hero::heroMoveTo(cocos2d::Point position)
{
	sprite->stopAllActions();
	this->position = sprite->getPosition();
	float distance = getDistance(this->position, position);
	auto* animate = createAnimate(getDirection(this->position, position), "run", 8);
	auto* move = MoveTo::create((float)distance / 50, position);
	auto* callFunc = CallFunc::create(CC_CALLBACK_0(Hero::heroResume, this));
	auto* sequence = Sequence::create(move, callFunc, NULL);
	sprite->runAction(animate);
	sprite->runAction(sequence);
}
void Hero::heroResume()
{
	sprite->stopAllActions();
	sprite->runAction(createAnimate(this->direction, "stand", 7));
}