#ifndef __BULLET_H__
#define __BULLET_H__

#include "cocos2d.h"
USING_NS_CC;

class Bullet :public Node
{
public:
	bool isActive;
	Sprite* bullet;
	void shoot(Point position);
	static Bullet* createBullet(Point position);
	void bulletInit(Point position);
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(Bullet);
};

#endif