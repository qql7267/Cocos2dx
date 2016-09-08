#ifndef __HROCKER_H__
#define __HROCKER_H__
#include "cocos2d.h"
using namespace cocos2d;

typedef enum{
	tag_rocker,
	tag_rockerBG,
}tagForRoocker;
class HRocker :public Layer
{
public:
	EventListenerTouchOneByOne* listener;
	static HRocker* createHRocker(const char* rockerImageName, const char* rockerBGImageName, Point position);
	void startRocker(bool _isStopOther);
	void stopRocker();
private:
	void rockerInit(const char* rockerImageName, const char* rockerBGImageName, Point position);
	Point getAnglePosition(float r, float angle);
	bool isCanMove;
	float getRad(Point pos1, Point pos2);
	Point rockerBGPosition;
	float rockerBGR;
	virtual bool onTouchBegan(Touch *touch, Event *event);
	virtual void onTouchMoved(Touch *touch, Event *event);
	virtual void onTouchEnded(Touch *touch, Event *event);
	CREATE_FUNC(HRocker);
};

#endif
