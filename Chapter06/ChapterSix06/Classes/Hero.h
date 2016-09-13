#ifndef __HERO_H__
#define __HERO_H__
#include "cocos2d.h"
USING_NS_CC;

class Hero :public Layer
{
public :
	int direction;
	Point position;
	Sprite* sprite;
	static Hero* createHeroSprite(Point position, int direction, const char* action);
	void heroInit(Point position, int direction, const char* action);
	virtual bool init();
	void runAttack(Hero* enemy);
	void doAttack();
	void runBack();
	void doStand();
	void beAttacked(float dt);
	void waiting();
	void waitingAtack();
	void waitingUpdate(float dt);
	Animate* createAnimate(int direction, const char* action, int num, int time);
	CREATE_FUNC(Hero);
};

#endif