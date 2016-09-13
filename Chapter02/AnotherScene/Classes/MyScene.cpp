#include "MyScene.h"
USING_NS_CC;
Scene* MyWorld::createScene()
{
	auto scene = Scene::create();
	auto layer = MyWorld::create();
	scene->addChild(layer);
	return scene;
}
bool MyWorld::init()
{
	if (!Layer::init())
	{
		return false;
	}
	auto pMenu = MenuItemImage::create("background1.png", "background1.png", this, menu_selector(MyWorld::menuBack));
	auto menu = Menu::create(pMenu, NULL);
	menu->setPosition(320, 180);
	this->addChild(menu);
	return true;
}
void MyWorld::menuBack(Ref* pSender)
{
	Director::sharedDirector()->replaceScene(HelloWorld::createScene());
}