#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
	cocos2d::Size size;
	cocos2d::TMXTiledMap* map;
	cocos2d::Sprite* sprite;
	cocos2d::TMXLayer* meta;
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
	void left(cocos2d::Object* pSender);
	void right(cocos2d::Object* pSender);
	void up(cocos2d::Object* pSender);
	void down(cocos2d::Object* pSender);
	bool isCanReach(float x, float y);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
