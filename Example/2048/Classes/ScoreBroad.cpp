#include "ScoreBroad.h"

ScoreBroad* ScoreBroad::createScoreBroad(int score, int width, int height, const char* title, int typt, float x, float y)
{
	ScoreBroad* enemy = new ScoreBroad();
	if (enemy&&enemy->init())
	{
		enemy->autorelease();
		enemy->enemyInit(score, width, height, title, typt, x, y);
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return NULL;
}
bool ScoreBroad::init()
{
	if (!Label::init())
	{
		return false;
	}
	return true;
}
void ScoreBroad::enemyInit(int score, int width, int height, const char* title, int typt, float x, float y)
{
	this->type = typt;
	this->score = score;
	if (typt == 1)
	{
		background = LayerColor::create(Color4B(2, 168, 209, 255), width, height);
		background->setPosition(x, y);
		addChild(background);
		scoreLabel = Label::create(String::createWithFormat("%d", score)->getCString(), "Arail.ttf", 40);
		scoreLabel->setPosition(width / 2, height / 2);
		background->addChild(scoreLabel);
	}
	else
	{
		background = LayerColor::create(Color4B(215, 224, 223, 255), width, height);
		background->setPosition(x, y);
		addChild(background);
		auto* label = Label::create(title, "Arail.ttf", 26);
		label->setPosition(width / 2, height - 20);
		background->addChild(label);
		scoreLabel = Label::create(String::createWithFormat("%d", score)->getCString(), "Arail.ttf", 34);
		scoreLabel->setPosition(width / 2, 30);
		background->addChild(scoreLabel);
	}
}
void ScoreBroad::setScore(int number)
{
	this->score = number;
	scoreLabel->setString(String::createWithFormat("%d", number)->getCString());
}
int ScoreBroad::getScore()
{
	return this->score;
}