#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "MyScene.h"

class HelloWorld : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// a selector callback
	//void menuCloseCallback(cocos2d::Ref* pSender);
	void menuButton011(cocos2d::Ref* pSender);
	void menuButton012(cocos2d::Ref* pSender);
	void menuButton013(cocos2d::Ref* pSender);
	void menuButton014(cocos2d::Ref* pSender);
	void menuButton015(cocos2d::Ref* pSender);
	void menuButton021(cocos2d::Ref* pSender);
	void menuButton022(cocos2d::Ref* pSender);
	void menuButton023(cocos2d::Ref* pSender);
	void menuButton024(cocos2d::Ref* pSender);
	void menuButton025(cocos2d::Ref* pSender);
	void menuButton031(cocos2d::Ref* pSender);
	void menuButton032(cocos2d::Ref* pSender);
	void menuButton033(cocos2d::Ref* pSender);
	void menuButton034(cocos2d::Ref* pSender);
	void menuButton035(cocos2d::Ref* pSender);

	// implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
