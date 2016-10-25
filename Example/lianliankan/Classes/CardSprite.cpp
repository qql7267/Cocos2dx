#include "CardSprite.h"

CardSprite* CardSprite::createCardSprite(int type, float x, float y)
{
	CardSprite* card = new CardSprite();
	if (card && card->init())
	{
		card->autorelease();
		card->cardInit(type, x, y);
		return card;
	}
	CC_SAFE_DELETE(card);
	return NULL;
}
bool CardSprite::init()
{
	if (!Layer::init())
	{
		return false;
	}
	return true;
}
void CardSprite::cardInit(int type, float x, float y)
{
	this->type = type;
	card = Sprite::create(String::createWithFormat("card%d.png", type)->getCString());
	card->setPosition(20 + 40 * x, 20 + 40 * y);
	addChild(card);
}
void CardSprite::cardDelete()
{
	this->type = 0;
	auto texture = Director::getInstance()->getTextureCache()->addImage("card0.png");
	auto frame = SpriteFrame::create("card0.png", Rect(0, 0, 40, 40));
	card->setDisplayFrame(frame);
}