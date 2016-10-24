#ifndef __ENEMYBULLET_H__
#define __ENEMYBULLET_H__

#include "cocos2d.h"
USING_NS_CC;

class EnemyBullet :public Node
{
public:
	bool isActive;
	Sprite* bullet;
	void shoot(Point position);
	static EnemyBullet* createBullet();
	void bulletInit();
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(EnemyBullet);
};

#endif