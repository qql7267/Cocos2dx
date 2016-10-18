#include "CardSprite.h"

#define CARD_BORDER 4

CardSprite* CardSprite::createCardSprite(int number, int size, float x, float y)
{
	CardSprite* enemy = new CardSprite();
	if (enemy &&enemy->init())
	{
		enemy->autorelease();
		enemy->enemyInit(number, size, x, y);
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return NULL;
}
bool CardSprite::init()
{
	if (!Sprite::init())
	{
		return false;
	}
	return true;
}
void CardSprite::enemyInit(int number, int size, float x, float y)
{
	this->number = number;
	layerColorBG = LayerColor::create(Color4B(216, 210, 214, 255), size - CARD_BORDER, size - CARD_BORDER);
	layerColorBG->setPosition(Point(x, y));
	if (number > 0)
	{
		labelNumber = Label::create(String::createWithFormat("%i", number)->getCString(), "Arial.ttf", 36);
		labelNumber->setPosition(Vec2((size - CARD_BORDER) / 2, (size - CARD_BORDER) / 2));
		layerColorBG->addChild(labelNumber);
	}
	else
	{
		labelNumber = Label::create("", "Arial.ttf", 28);
		labelNumber->setPosition(Vec2(size / 2, size / 2));
		layerColorBG->addChild(labelNumber);
	}
	this->addChild(layerColorBG);
}
int CardSprite::getNumber()
{
	return this->number;
}
void CardSprite::setNumber(int num)
{
	number = num;
	if (number > 0)
	{
		labelNumber->setString(String::createWithFormat("%i", number)->getCString());
		if (number == 2)
		{
			layerColorBG->setColor(Color3B(255, 246, 247));
			labelNumber->setColor(Color3B(33, 33, 7));
			labelNumber->setSystemFontSize(44);
		}
		else if (number == 4)
		{
			layerColorBG->setColor(Color3B(255, 218, 163));
			labelNumber->setColor(Color3B(255, 255, 255));
			labelNumber->setSystemFontSize(44);
		}
		else if (number == 8)
		{
			layerColorBG->setColor(Color3B(255, 144, 91));
			labelNumber->setSystemFontSize(44);
		}
		else if (number == 16)
		{
			layerColorBG->setColor(Color3B(255, 101, 16));
			labelNumber->setSystemFontSize(38);
		}
		else if (number == 32)
		{
			layerColorBG->setColor(Color3B(255, 80, 46));
			labelNumber->setSystemFontSize(38);
		}
		else if (number == 64)
		{
			layerColorBG->setColor(Color3B(254, 56, 46));
			labelNumber->setSystemFontSize(38);
		}
		else if (number == 128)
		{
			layerColorBG->setColor(Color3B(6, 194, 2420));
			labelNumber->setSystemFontSize(34);
		}
		else if (number == 256)
		{
			layerColorBG->setColor(Color3B(5, 142, 247));
			labelNumber->setSystemFontSize(34);
		}
		else if (number == 512)
		{
			layerColorBG->setColor(Color3B(4, 140, 200));
			labelNumber->setSystemFontSize(34);
		}
		else if (number == 1024)
		{
			layerColorBG->setColor(Color3B(3, 112, 154));
			labelNumber->setSystemFontSize(28);
		}
		else if (number == 2048)
		{
			layerColorBG->setColor(Color3B(2, 98, 131));
			labelNumber->setSystemFontSize(28);
		}
		else if (number == 4096)
		{
			layerColorBG->setColor(Color3B(1, 93, 118));
			labelNumber->setSystemFontSize(28);
		}
		else if (number == 8192)
		{
			layerColorBG->setColor(Color3B(58, 49, 132));
			labelNumber->setSystemFontSize(28);
		}
		else if (number == 16384)
		{
			layerColorBG->setColor(Color3B(41, 41, 49));
			labelNumber->setSystemFontSize(24);
		}
		else if (number == 32768)
		{
			layerColorBG->setColor(Color3B(33, 33, 7));
			labelNumber->setSystemFontSize(24);
		}
		else
		{
			layerColorBG->setColor(Color3B(0, 0, 0));
			labelNumber->setSystemFontSize(24);
		}
	}
	else
	{
		labelNumber->setString("");
		layerColorBG->setColor(Color3B(216, 210, 214));
	}
}