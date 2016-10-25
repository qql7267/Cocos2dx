#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__
#include "CardSprite.h"
#include "CountDownBar.h"
#include "cocos2d.h"
USING_NS_CC;

#define WIDTH 12
#define HEIGHT 9
#define SIZE 40
#define FULLTIME 1000

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
	Point temp;
	TMXLayer* recLayer;
	CardSprite* card[12][9];
	Sprite* cardSprite[12][9];
	bool timeOut;
	int time;
	CountDownBar* bar;
	int propNum;
	Label* scoreLabel;
	Label* timeLabel;
	Label* propLabel;
	int score;

    virtual bool init();
	void initBoard();
	bool onTouchBegan(Touch *touch, Event *unused_event);
	bool noCorner(int x1, int y1, int x2, int y2);
	bool oneCorner(int x1, int y1, int x2, int y2);
	bool twoCorner(int x1, int y1, int x2, int y2);
	bool isCanConnection(int x1, int y1, int x2, int y2);
	void update(float dt);
	void prop(Ref* pSender);

    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
