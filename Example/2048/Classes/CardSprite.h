#ifndef __CARTSPRITE_H__
#define __CARTSPRITE_H__

#include "cocos2d.h"
USING_NS_CC;

class CardSprite :public Sprite
{
public:
	int number;
	int getNumber();
	void setNumber(int num);
	Label* labelNumber;
	LayerColor* layerColorBG;
	static CardSprite* createCardSprite(int number, int size, float x, float y);
	void enemyInit(int number, int size, float x, float y);
	virtual bool init();
	CREATE_FUNC(CardSprite);
};

#endif // !__CARTSPRITE_H__
