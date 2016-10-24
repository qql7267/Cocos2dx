#ifndef __HEROPLANE_H__
#define __HEROPLANE_H__

#include "cocos2d.h"
USING_NS_CC;

class HeroPlane :public Layer
{
public:
	Sprite* plane;
	Point prePos;
	Point position;
	bool isFlip;
	static HeroPlane* createHeroPlane(Point position);
	void heroPlaneInit(Point position);
	Animate* actionFly();
	static Scene* createScene();
	virtual bool init();
	void planeMove(Point point, Point relative);
	CREATE_FUNC(HeroPlane);
};

#endif