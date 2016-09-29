#ifndef __SLIDE_H__
#define __SLIDE_H__
#include "cocos2d.h"
USING_NS_CC;
class SlideBar : public Layer
{
public:
	int size;
	bool isTouched;
	static SlideBar* createBar(int size, Point poing, int number);
	void barInit(int size, Point position, int number);
	virtual bool onTouchBegan(Touch *touch, Event *unused_event);
	virtual void onTouchMoved(Touch *touch, Event *unused_event);
	virtual void onTouchEnded(Touch *touch, Event *unused_event);
	CREATE_FUNC(SlideBar);
};

#endif