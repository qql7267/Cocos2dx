#ifndef __COUNTDOWNBAR_H__
#define __COUNTDOWNBAR_H__

#include "cocos2d.h"
USING_NS_CC;

class CountDownBar :public Layer
{
public:
	Sprite* barBG;
	Sprite* countDownBar;
	void barUpdate(int timeNow, int timeFull);
	static CountDownBar* createCounDownBar(Point position, int size);
	void countDownBarInit(Point position, int size);
	static Scene* createScene();
	virtual bool init();
	CREATE_FUNC(CountDownBar);
};

#endif