#ifndef __STARSPRITE_H__
#define __STARSPRITE_H__

#include "cocos2d.h"
USING_NS_CC;

class StarSprite :public Layer
{
public:
	int type;
	Sprite* star;
	void starDelete();
	static StarSprite* createStar(int type, float x, float y);
	void starInit(int type, float x, float y);
	void moveTo(float dt, int x, int y);
	virtual bool init();
	CREATE_FUNC(StarSprite);
};

#endif