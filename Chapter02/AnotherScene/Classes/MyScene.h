#ifndef __MYWORLD_SCENE_H__
#define __MYWORLD_SCENE_H__

#include "cocos2d.h"
#include "HelloWorldScene.h"
class MyWorld :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();	// 静态函数，用户获取场景对象
	virtual bool init();					// 初始化场景
	void menuBack(cocos2d::Ref* pSender);
	CREATE_FUNC(MyWorld);					// 这里使用了一个宏
};
#endif

