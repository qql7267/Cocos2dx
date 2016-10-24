#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
	number = (unsigned)time(NULL);
	enemyBulletLock = 0;
	addChild(addBackground());

	hero = HeroPlane::createHeroPlane(Vec2(180, 100));
	hero->setTag(HERO_TAG);
	hero->position = Vec2(180, 100);
	addChild(hero);

	preBullet();
	preEnemy();

	auto* dispatcher = Director::getInstance()->getEventDispatcher();
	auto* listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	scheduleUpdate();

    return true;
}
void HelloWorld::update(float dt)
{
	setBackground();
	productBullet();
	productEnemy();
	checkEnemy();
	checkHero();
}
Layer* HelloWorld::addBackground()
{
	auto* layerBG = Layer::create();

	background[0] = Sprite::create("background.png");
	background[0]->setAnchorPoint(Vec2(0, 0));
	background[0]->setPosition(0, 0);
	layerBG->addChild(background[0]);

	background[1] = Sprite::create("background.png");
	background[1]->setAnchorPoint(Vec2(0, 0));
	background[1]->setPosition(0, BACKGROUND_HEIGHT);
	layerBG->addChild(background[1]);

	background[2] = Sprite::create("plane_background.png");
	background[2]->setAnchorPoint(Vec2(0, 0));
	background[2]->setPosition(0, -BACKGROUND_HEIGHT);
	layerBG->addChild(background[2]);

	background[3] = Sprite::create("plane_background.png");
	background[3]->setAnchorPoint(Vec2(0, 0));
	background[3]->setPosition(0, -BACKGROUND_HEIGHT * 2);
	layerBG->addChild(background[3]);

	return layerBG;
}
void HelloWorld::setBackground()
{
	background[0]->setPositionY(background[0]->getPositionY() - 1);
	background[1]->setPositionY(background[1]->getPositionY() - 1);

	if (background[0]->getPositionY() < -BACKGROUND_HEIGHT)
	{
		background[0]->setPositionY(BACKGROUND_HEIGHT);
	}
	if (background[1]->getPositionY() < -BACKGROUND_HEIGHT)
	{
		background[1]->setPositionY(BACKGROUND_HEIGHT);
	}

	background[2]->setPositionY(background[2]->getPositionY() + 2);
	background[3]->setPositionY(background[3]->getPositionY() + 2);

	if (background[2]->getPositionY() > BACKGROUND_HEIGHT)
	{
		background[2]->setPositionY(-BACKGROUND_HEIGHT);
	}
	if (background[3]->getPositionY() > BACKGROUND_HEIGHT)
	{
		background[3]->setPositionY(-BACKGROUND_HEIGHT);
	}
}
bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{
	auto* hero = (HeroPlane*)getChildByTag(HERO_TAG);
	Point point = touch->getLocation();
	if (hero->plane->boundingBox().containsPoint(point))
	{
		relativePos = Vec2(point.x - hero->position.x, point.y - hero->position.y);
		return true;
	}
	return false;
}
void HelloWorld::onTouchMoved(Touch *touch, Event *unused_event)
{
	auto* hero = (HeroPlane*)getChildByTag(HERO_TAG);
	Point point = touch->getLocation();
	hero->planeMove(point,relativePos);
}
void HelloWorld::onTouchEnded(Touch *touch, Event *unused_event)
{
	auto* hero = (HeroPlane*)getChildByTag(HERO_TAG);
	hero->plane->setRotation3D(Vec3(0, 0, 0));
}
void HelloWorld::preBullet()
{
	for (int i = 0; i < BULLET_NUMBER; i++)
	{
		bullet[i] = Bullet::createBullet(Vec2(0, 660));
		addChild(bullet[i]);
	}
	for (int i = 0; i < ENEMYBULLET_NUMBER; i++)
	{
		enemyBullet[i] = EnemyBullet::createBullet();
		addChild(enemyBullet[i]);
	}
}
void HelloWorld::productBullet()
{
	auto* hero = (HeroPlane*)getChildByTag(HERO_TAG);
	for (int i = 0; i < BULLET_NUMBER; i++)
	{
		if (bullet[i]->isActive == false)
		{
			bullet[i]->isActive = true;
			bullet[i]->shoot(hero->position);
			break;
		}
	}
	for (int i = 0; i < BULLET_NUMBER; i++)
	{
		if (bullet[i]->isActive&&bullet[i]->bullet->getPositionY() == 660)
		{
			bullet[i]->isActive = false;
		}
	}
	if (enemyBulletLock % 100 == 0)
	{
		for (int i = 0; i < ENEMY_NUMBER; i++)
		{
			if (enemy[i]->type == 1)
			{
				for (int j = 0; j < ENEMYBULLET_NUMBER; j++)
				{
					if (enemyBullet[j]->isActive == false)
					{
						enemyBullet[j]->shoot(enemy[i]->enemy->getPosition());
						break;
					}
				}
			}
		}
	}
	enemyBulletLock++;
	for (int i = 0; i < ENEMYBULLET_NUMBER; i++)
	{
		if (enemyBullet[i]->bullet->getPositionY() == -80)
		{
			enemyBullet[i]->isActive == false;
		}
	}
}
void HelloWorld::preEnemy()
{
	for (int i = 0; i < ENEMY_NUMBER; i++)
	{
		enemy[i] = EnemyPlane::createEnemy();
		addChild(enemy[i]);
	}
}
void HelloWorld::productEnemy()
{
	srand(number);
	number = rand();
	int num = number % 150;
	bool isProduce = false;
	int type = 0;
	if (num == 1)
	{
		type = 1;
		isProduce = true;
	}
	else if (num == 2 || num == 4)
	{
		type = 2;
		isProduce = true;
	}
	else if (num == 3 || num == 6 || num == 9 || num == 0)
	{
		type = 3;
		isProduce = true;
	}
	if (isProduce)
	{
		for (int i = 0; i < ENEMY_NUMBER; i++)
		{
			if (enemy[i]->type == 0)
			{
				int positionX = rand() % 360;
				enemy[i]->start(type, positionX);
				break;
			}
		}
	}
	for (int i = 0; i < ENEMY_NUMBER; i++)
	{
		if (enemy[i]->enemy->getPositionY() == END_HEIGHT)
		{
			enemy[i]->type = 0;
		}
	}
}
void HelloWorld::checkEnemy()
{
	for (int i = 0; i < BULLET_NUMBER; i++)
	{
		if (bullet[i]->isActive)
		{
			for (int j = 0; j < ENEMY_NUMBER; j++)
			{
				if (enemy[j]->type > 0)
				{
					float r = 0;
					if (enemy[j]->type == 1)
					{
						r = 64.0f;
					}
					else if (enemy[j]->type == 2)
					{
						r = 32.0f;
					}
					else if (enemy[j]->type == 3)
					{
						r = 10.0f;
					}
					float dx = bullet[i]->bullet->getPositionX() - enemy[j]->enemy->getPositionX();
					float dy = bullet[i]->bullet->getPositionY() - enemy[j]->enemy->getPositionY();
					float d = sqrt(dx * dx + dy * dy);
					if (d < r)
					{
						enemy[j]->enemyDestory();
						bullet[i]->bullet->stopAllActions();
						bullet[i]->bullet->setPosition(0, 660);
						bullet[i]->isActive = false;
					}
				}
			}
		}
	}
}
void HelloWorld::checkHero()
{
	auto* hero = (HeroPlane*)getChildByTag(HERO_TAG);
	for (int i = 0; i < ENEMY_NUMBER; i++)
	{
		if (enemy[i]->type == 0)
		{
			auto point = enemy[i]->enemy->getPosition();
			if (hero->plane->boundingBox().containsPoint(point))
			{
				CCLOG("pi da ye is boom!");
			}
		}
	}
	for (int i = 0; i < ENEMYBULLET_NUMBER; i++)
	{
		if (enemyBullet[i]->isActive)
		{
			auto point = enemyBullet[i]->bullet->getPosition();
			if (hero->plane->boundingBox().containsPoint(point))
			{
				CCLOG("pi da ye is pang!");
			}
		}
	}
}