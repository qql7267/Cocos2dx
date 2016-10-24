#ifndef __ENEMYPLANE_H__
#define __ENEMYPLANE_H__

#include "cocos2d.h"
USING_NS_CC;

#define START_HEIGHT 720
#define END_HEIGHT -80

class EnemyPlane :public Layer
{
public:
	int type;
	int blood;
	Sprite* enemy;
	void start(int type, int positionX);
	static EnemyPlane* createEnemy();
	void EnemyInit();
	static Scene* createScene();
	virtual bool init();
	void enemyDestory();
	CREATE_FUNC(EnemyPlane);
};

#endif