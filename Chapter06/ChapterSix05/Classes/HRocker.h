#ifndef __HROCKER_H__
#define __HROCKER_H__
#include "cocos2d.h"  
using namespace cocos2d;
enum hero_direction
{
	RIGHT_DOWN = 1,
	LEFT_DOWN = 2,
	LEFT_UP = 3,
	RIGHT_UP = 4,
	DOWN = 5,
	LEFT = 6,
	UP = 7,
	RIGHT = 8
};
#define PI 3.1415926
//ö���ͣ����ڱ�ʶҡ����ҡ�˵ı���  
typedef enum{
	tag_rocker,
	tag_rockerBG,
}tagForHRocker;
class HRocker : public Layer
{
public:
	float dx;
	float dy;
	int direction;
	//�Ƿ�ɲ���ҡ��  
	bool isCanMove;
	//����ҡ�ˣ�ҡ��ͼƬ��ҡ�˱���ͼƬ����ʼ����  
	static HRocker* createHRocker(const char* rockerImageName, const char* rockerBGImageName, Point position);
	//����ҡ��  
	void startRocker(bool _isStopOther);
	//ֹͣҡ��  
	void stopRocker();
private:
	EventListenerTouchOneByOne* listener;
	void rockerInit(const char* rockerImageName, const char* rockerBGImageName, Point position);
	//�õ��뾶Ϊr��Բ���˶���һ���Ƕ�Ӧ��Ӧ��x,y����  
	Point getAnglePosition(float r, float angle);
	//�õ�ҡ�����û�������ĽǶ�  
	float getRad(Point pos1, Point pos2);
	//ҡ�˱���������  
	Point rockerBGPosition;
	//ҡ�˱����İ뾶  
	float rockerBGR;
	//�����¼�  
	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);
	CREATE_FUNC(HRocker);
};

#endif  