#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CardSprite.h"
#include "ScoreBroad.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	bool isLock;
	float x;
	float y;
	CardSprite* card[4][4];
	int record;
	int score;
	int demo;
	ScoreBroad* broad1;
	ScoreBroad* broad2;
	ScoreBroad* broad3;
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	void createCard();
	void scoreAddUp(ScoreBroad* broad, int number);
	void refreshBroad(int x);
	bool doLeft();
	bool doRight();
	bool doUp();
	bool doDown();
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
