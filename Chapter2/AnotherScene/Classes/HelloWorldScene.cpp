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
	if (!Layer::init())
	{
		return false;
	}

	auto *pBackground = Sprite::create("background.png");
	pBackground->setPosition(320, 180);
	this->addChild(pBackground);

	auto pMenu11 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton011));
	auto label11 = LabelTTF::create("001", "Arial", 18);
	auto pLabel11 = MenuItemLabel::create(label11);
	auto menu11 = Menu::create(pMenu11, pLabel11, NULL);
	menu11->setPosition(64 + 128 * 0, 300);
	this->addChild(menu11);

	auto pMenu12 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton012));
	auto label12 = LabelTTF::create("002", "Arial", 18);
	auto pLabel12 = MenuItemLabel::create(label12);
	auto menu12 = Menu::create(pMenu12, pLabel12, NULL);
	menu12->setPosition(64 + 128 * 1, 300);
	this->addChild(menu12);

	auto pMenu13 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton013));
	auto label13 = LabelTTF::create("003", "Arial", 18);
	auto pLabel13 = MenuItemLabel::create(label13);
	auto menu13 = Menu::create(pMenu13, pLabel13, NULL);
	menu13->setPosition(64 + 128 * 2, 300);
	this->addChild(menu13);

	auto pMenu14 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton014));
	auto label14 = LabelTTF::create("004", "Arial", 18);
	auto pLabel14 = MenuItemLabel::create(label14);
	auto menu14 = Menu::create(pMenu14, pLabel14, NULL);
	menu14->setPosition(64 + 128 * 3, 300);
	this->addChild(menu14);

	auto pMenu15 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton015));
	auto label15 = LabelTTF::create("005", "Arial", 18);
	auto pLabel15 = MenuItemLabel::create(label15);
	auto menu15 = Menu::create(pMenu15, pLabel15, NULL);
	menu15->setPosition(64 + 128 * 4, 300);
	this->addChild(menu15);

	auto pMenu21 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton021));
	auto label21 = LabelTTF::create("006", "Arial", 18);
	auto pLabel21 = MenuItemLabel::create(label21);
	auto menu21 = Menu::create(pMenu21, pLabel21, NULL);
	menu21->setPosition(64 + 128 * 0, 180);
	this->addChild(menu21);

	auto pMenu22 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton022));
	auto label22 = LabelTTF::create("007", "Arial", 18);
	auto pLabel22 = MenuItemLabel::create(label22);
	auto menu22 = Menu::create(pMenu22, pLabel22, NULL);
	menu22->setPosition(64 + 128 * 1, 180);
	this->addChild(menu22);

	auto pMenu23 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton023));
	auto label23 = LabelTTF::create("008", "Arial", 18);
	auto pLabel23 = MenuItemLabel::create(label23);
	auto menu23 = Menu::create(pMenu23, pLabel23, NULL);
	menu23->setPosition(64 + 128 * 2, 180);
	this->addChild(menu23);

	auto pMenu24 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton024));
	auto label24 = LabelTTF::create("009", "Arial", 18);
	auto pLabel24 = MenuItemLabel::create(label24);
	auto menu24 = Menu::create(pMenu24, pLabel24, NULL);
	menu24->setPosition(64 + 128 * 3, 180);
	this->addChild(menu24);

	auto pMenu25 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton025));
	auto label25 = LabelTTF::create("010", "Arial", 18);
	auto pLabel25 = MenuItemLabel::create(label25);
	auto menu25 = Menu::create(pMenu25, pLabel25, NULL);
	menu25->setPosition(64 + 128 * 4, 180);
	this->addChild(menu25);

	auto pMenu31 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton031));
	auto label31 = LabelTTF::create("011", "Arial", 18);
	auto pLabel31 = MenuItemLabel::create(label31);
	auto menu31 = Menu::create(pMenu31, pLabel31, NULL);
	menu31->setPosition(64 + 128 * 0, 60);
	this->addChild(menu31);

	auto pMenu32 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton032));
	auto label32 = LabelTTF::create("012", "Arial", 18);
	auto pLabel32 = MenuItemLabel::create(label32);
	auto menu32 = Menu::create(pMenu32, pLabel32, NULL);
	menu32->setPosition(64 + 128 * 1, 60);
	this->addChild(menu32);

	auto pMenu33 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton033));
	auto label33 = LabelTTF::create("013", "Arial", 18);
	auto pLabel33 = MenuItemLabel::create(label33);
	auto menu33 = Menu::create(pMenu33, pLabel33, NULL);
	menu33->setPosition(64 + 128 * 2, 60);
	this->addChild(menu33);

	auto pMenu34 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton034));
	auto label34 = LabelTTF::create("014", "Arial", 18);
	auto pLabel34 = MenuItemLabel::create(label34);
	auto menu34 = Menu::create(pMenu34, pLabel34, NULL);
	menu34->setPosition(64 + 128 * 3, 60);
	this->addChild(menu34);

	auto pMenu35 = MenuItemImage::create("button.png", "button_a.png", this, menu_selector(HelloWorld::menuButton035));
	auto label35 = LabelTTF::create("015", "Arial", 18);
	auto pLabel35 = MenuItemLabel::create(label35);
	auto menu35 = Menu::create(pMenu35, pLabel35, NULL);
	menu35->setPosition(64 + 128 * 4, 60);
	this->addChild(menu35);

	return true;
}

void HelloWorld::menuButton011(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionFade::create(3.0f, MyWorld::createScene()));
}

void HelloWorld::menuButton012(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionFadeBL::create(3.0f, MyWorld::createScene()));
}
void HelloWorld::menuButton013(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionFadeTR::create(3.0f, MyWorld::createScene()));
}
void HelloWorld::menuButton014(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionTurnOffTiles::create(3.0f, MyWorld::createScene()));
}
void HelloWorld::menuButton015(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionJumpZoom::create(3.0f, MyWorld::createScene()));
}

void HelloWorld::menuButton021(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionMoveInL::create(3.0f, MyWorld::createScene()));
}
void HelloWorld::menuButton022(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionSplitCols::create(3.0f, MyWorld::createScene()));
}
void HelloWorld::menuButton023(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionProgressRadialCW::create(3.0f, MyWorld::createScene()));
}
void HelloWorld::menuButton024(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionRotoZoom::create(3.0f, MyWorld::createScene()));
}
void HelloWorld::menuButton025(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionShrinkGrow::create(3.0f, MyWorld::createScene()));
}

void HelloWorld::menuButton031(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionSlideInL::create(3.0f, MyWorld::createScene()));
}
void HelloWorld::menuButton032(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionCrossFade::create(3.0f, MyWorld::createScene()));
}
void HelloWorld::menuButton033(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionProgressRadialCCW::create(3.0f, MyWorld::createScene()));
}
void HelloWorld::menuButton034(Ref* pSender)
{
	//Director::sharedDirector()->replaceScene(TransitionPageTurn::create(3.0f, MyWorld::createScene()));
}
void HelloWorld::menuButton035(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(TransitionSplitCols::create(3.0f, MyWorld::createScene()));
}
