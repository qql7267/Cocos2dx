#ifndef __MYWORLD_SCENE_H__
#define __MYWORLD_SCENE_H__

#include "cocos2d.h"
#include "HelloWorldScene.h"
class MyWorld :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();	// ��̬�������û���ȡ��������
	virtual bool init();					// ��ʼ������
	void menuBack(cocos2d::Ref* pSender);
	CREATE_FUNC(MyWorld);					// ����ʹ����һ����
};
#endif

