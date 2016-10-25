#ifndef __MYWORLD_H__
#define __MYWORLD_H__
#include "HelloWorldScene.h"
#include "cocos2d.h"
USING_NS_CC;

class MyWorld : public Layer
{
public:
	int iniX;
	int id;
	static Scene* createScene();
	bool init();
	void menu(Ref* pSender);
	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	CREATE_FUNC(MyWorld);
};

#endif