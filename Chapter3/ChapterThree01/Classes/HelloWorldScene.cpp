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
char* HelloWorld::FontToUTF8(const char* font)
{
	int len = MultiByteToWideChar(CP_ACP, 0, font, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(CP_ACP, 0, font, -1, wstr, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr)delete[] wstr;
	return str;
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

	auto label = Label::create(HelloWorld::FontToURF8("»¶Ó­Ê¹ÓÃCocos2d-x"), "Arial", 36, Size::ZERO, TextHAlignment::LEFT, TextVAlignment::TOP);
	label->setPosition(210, 370);
	addChild(label);

	auto label1 = Label::create("This is the first label", "Arial", 36);
	label1->setPosition(210, 310);
	addChild(label1);

	TTFConfig ttfconfig("fonts/chunkmuffinhollowwide.ttf", 36);
	auto label2 = Label::createWithTTF(ttfconfig, "This is the second label");
	label2->setPosition(270, 250);
	addChild(label2);

	auto label3 = Label::createWithTTF("This is the third label", "fonts/Marker Felt.ttf", 36);
	label3->setPosition(200, 190);
	addChild(label3);

	auto label4 = Label::createWithTTF("This is the fourth label", "fonts/Marker Felt.ttf", 36);
	label4->setPosition(220, 130);
	label4->enableShadow(Color4B::GREEN, Size(5, 5));
	label4->enableOutline(Color4B::RED, 3);
	addChild(label4);

	auto label5 = Label::createWithTTF("This is the fifth label", "fonts/Marker Felt.ttf", 36);
	label5->setPosition(210, 30);
	label5->enableGlow(Color4B::GREEN);
	addChild(label5);

    return true;
}

