#ifndef __SCOREBROAD_H__
#define __SCOREBROAD_H__

#include "cocos2d.h"
USING_NS_CC;

class ScoreBroad :public Label
{
public:
	int type;
	int score;
	void setScore(int number);
	int getScore();
	Label* scoreLabel;
	LayerColor* background;
	static ScoreBroad* createScoreBroad(int score, int width, int height, const char* title, int typt, float x, float y);
	void enemyInit(int score, int width, int height, const char* title, int typt, float x, float y);
	virtual bool init();
	CREATE_FUNC(ScoreBroad);
};

#endif // !__SCOREBROAD_H__
