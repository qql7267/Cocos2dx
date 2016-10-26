#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "StarSprite.h"
#include <ctime>

#define WIDTH 9
#define HEIGHT 16

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	StarSprite* star[WIDTH][HEIGHT];
	int holder[HEIGHT*WIDTH];
	int starX;
	int starY;
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	void addStar();
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void UDLRDelete(int x, int y);
	void addToHolder(int x, int y);
	void cleanHolder();
	void popStar();
	void starDrop();
	void starTranslation();
	void starMove(float dt);
	bool isOver();
	void starStart();
	void update(float dt);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
