#include "HRocker.h"
USING_NS_CC;
HRocker* HRocker::createHRocker(const char *rockerImageName, const char *rockerBGImageName, Point position)
{
	HRocker* layer = HRocker::create();
	if (layer)
	{
		layer->rockerInit(rockerImageName, rockerBGImageName, position);
		return layer;
	}
	CC_SAFE_DELETE(layer);
	return NULL;
}
void HRocker::rockerInit(const char *rockerImageName, const char *rockerBGImageName, Point position)
{
	direction = 1;
	//���ҡ�˱���ͼ  
	Sprite* spRockerBG = Sprite::create(rockerBGImageName);
	spRockerBG->setVisible(false);
	spRockerBG->setPosition(position);
	spRockerBG->setScale(1.3f);
	addChild(spRockerBG, 0, tag_rockerBG);
	//���ҡ���Ϸ��Ǹ����ƶ���ͼ  
	Sprite* spRocker = Sprite::create(rockerImageName);
	spRocker->setVisible(false);
	spRocker->setPosition(position);
	spRocker->setScale(1.3f);
	addChild(spRocker, 1, tag_rocker);
	spRocker->setOpacity(180);
	//ҡ�˱���ͼ����  
	rockerBGPosition = position;
	//ҡ�˱���ͼ�뾶  
	rockerBGR = spRockerBG->getContentSize().width*0.5;
	listener = EventListenerTouchOneByOne::create();
	// �󶨼����¼�
	listener->onTouchBegan = CC_CALLBACK_2(HRocker::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HRocker::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HRocker::onTouchEnded, this);
	listener->setSwallowTouches(true);
}
//����ҡ��  
void HRocker::startRocker(bool _isStopOther)
{
	//�������ÿɼ������ü���  
	Sprite* rocker = (Sprite*)getChildByTag(tag_rocker);
	rocker->setVisible(true);
	Sprite* rockerBG = (Sprite*)getChildByTag(tag_rockerBG);
	rockerBG->setVisible(true);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}
//ֹͣҡ��  
void HRocker::stopRocker()
{
	//�������ò��ɼ���ȡ������  
	Sprite* rocker = (Sprite*)getChildByTag(tag_rocker);
	rocker->setVisible(false);
	Sprite* rockerBG = (Sprite*)getChildByTag(tag_rockerBG);
	rockerBG->setVisible(false);
	Director::getInstance()->getEventDispatcher()->removeEventListener(listener);
}
//�õ�������ĽǶ�ֵ  
float HRocker::getRad(Point pos1, Point pos2)
{
	//�õ����������x,y����ֵ  
	float px1 = pos1.x;
	float py1 = pos1.y;
	float px2 = pos2.x;
	float py2 = pos2.y;
	//������߳���  
	float x = px2 - px1;
	float y = py1 - py2;
	//����   ��  ���η� ��ʽ  
	float xie = sqrt(pow(x, 2) + pow(y, 2));
	float cos = x / xie;
	//�����Ҷ���֪�����߳���Ƕȣ�cos = �ڱ�/б��  
	float rad = acos(cos);
	//������Y���� <ҡ�˵�Y����ʱ��ȡ��ֵ  
	if (py1 > py2)
	{
		rad = -rad;
	}
	return rad;
}
//�õ���Ƕȶ�Ӧ�İ뾶Ϊr��Բ��һ�����  
Point HRocker::getAnglePosition(float r, float angle)
{
	return ccp(r*cos(angle), r*sin(angle));
}
bool HRocker::onTouchBegan(Touch *touch, Event *event)
{
	Sprite* sp = (Sprite*)getChildByTag(tag_rocker);
	//�õ�����������  
	Point point = touch->getLocation();
	//�ж��Ƿ�����sp������飺boundingBox()�����С֮�ڵ���������  
	if (sp->boundingBox().containsPoint(point))
	{
		isCanMove = true;
	}
	return true;
}
void HRocker::onTouchMoved(Touch *touch, Event *event)
{
	if (!isCanMove)
	{
		return;
	}
	Sprite* sp = (Sprite*)getChildByTag(tag_rocker);
	Point point = touch->getLocation();
	//�ж�����Բ�ĵľ����Ƿ����ҡ�˱����İ뾶  
	if (sqrt(pow(point.x - rockerBGPosition.x, 2) + pow(point.y - rockerBGPosition.y, 2)) >= rockerBGR)
	{
		//�õ�������ҡ�˱���Բ���γɵĽǶ�  
		float angle = getRad(rockerBGPosition, point);
		//ȷ��СԲ�˶���Χ�ڱ���Բ��  
		sp->setPosition(ccpAdd(getAnglePosition(rockerBGR, angle), ccp(rockerBGPosition.x, rockerBGPosition.y)));
	}
	else {
		//�����ڱ���Բ������津���˶�  
		sp->setPosition(point);
	}
	// ��ȡ����
	auto basePosition = ((Sprite*)getChildByTag(tag_rockerBG))->getPosition();
	this->dx = sp->getPosition().x - basePosition.x;
	this->dy = sp->getPosition().y - basePosition.y;
	float r = sqrt(dx*dx + dy*dy);
	if (dx > 0 && fabs(dy / r) < sin(15 * PI / 180))
	{
		//CCLOG("RIGHT");
		this->direction = 8;
	}
	else if (dx < 0 && fabs(dy / r) < sin(15 * PI / 180))
	{
		//CCLOG("LEFT");
		this->direction = 6;
	}
	else if (dy > 0 && fabs(dx / r) < sin(15 * PI / 180))
	{
		//CCLOG("UP");
		this->direction = 7;
	}
	else if (dy < 0 && fabs(dx / r) < sin(15 * PI / 180))
	{
		//CCLOG("DOWN");
		this->direction = 5;
	}
	else if (dx > 0 && dy > 0)
	{
		//CCLOG("RIGHT-UP");
		this->direction = 4;
	}
	else if (dx > 0 && dy < 0)
	{
		//CCLOG("RIGHT-DOWN");
		this->direction = 1;
	}
	else if (dx < 0 && dy < 0)
	{
		//CCLOG("LEFT-DOWN");
		this->direction = 2;
	}
	else if (dx < 0 && dy > 0)
	{
		//CCLOG("LEFT-UP");
		this->direction = 3;
	}
}
void HRocker::onTouchEnded(Touch *touch, Event *event)
{
	if (!isCanMove)
	{
		return;
	}
	Sprite* rocker = (Sprite*)getChildByTag(tag_rocker);
	Sprite* rockerBG = (Sprite*)getChildByTag(tag_rockerBG);
	rocker->stopAllActions();
	rocker->runAction(MoveTo::create(0.08, rockerBG->getPosition()));
	isCanMove = false;
}