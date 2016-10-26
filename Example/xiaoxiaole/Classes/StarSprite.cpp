#include "StarSprite.h"

StarSprite* StarSprite::createStar(int type, float x, float y)
{
	StarSprite* star = new StarSprite();
	if (star&&star->init())
	{
		star->autorelease();
		star->starInit(type, x, y);
		return star;
	}
	CC_SAFE_DELETE(star);
	return NULL;
}
bool StarSprite::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
void StarSprite::starInit(int type, float x, float y)
{
	this->type = type;
	star = Sprite::create(String::createWithFormat("card%d.png", type)->getCString());
	star->setPosition(20 + 40 * x, 20 + 40 * y);
	addChild(star);
}
void StarSprite::starDelete()
{
	this->type = 0;
	auto texture = Director::getInstance()->getTextureCache()->addImage("card0.png");
	auto frame = SpriteFrame::create("card0.png", Rect(0, 0, 40, 40));
	star->setDisplayFrame(frame);
}
void StarSprite::moveTo(float dt, int x, int y)
{
	auto* move = MoveTo::create(dt, Vec3(20 + 40 * x, 20 + 40 * y, 0));
	this->star->runAction(move);
}