#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "HeroPlane.h"
#include "Bullet.h"
#include "EnemyPlane.h"
#include "EnemyBullet.h"
USING_NS_CC;

#define BACKGROUND_HEIGHT 638
#define BACKGROUND_WIDTH 360
#define HERO_TAG 1
#define BULLET_NUMBER 15
#define ENEMY_NUMBER 10
#define ENEMYBULLET_NUMBER 30

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	Sprite* background[4];
	HeroPlane* hero;
	Point relativePos;
	Bullet* bullet[BULLET_NUMBER];
	EnemyPlane* enemy[ENEMY_NUMBER];
	int number;
	EnemyBullet* enemyBullet[ENEMYBULLET_NUMBER];
	int enemyBulletLock;
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	Layer* addBackground();
	void setBackground();
	void update(float dt);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	void preBullet();
	void productBullet();
	void preEnemy();
	void productEnemy();
	void checkEnemy(); 
	void checkHero();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
