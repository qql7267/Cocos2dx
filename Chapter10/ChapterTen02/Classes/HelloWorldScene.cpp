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
    
	auto* background = LayerColor::create(Color4B(255, 255, 255, 255));
	addChild(background);

	auto* readLabel = Label::create("read", "Courier", 56);
	readLabel->setColor(Color3B(0, 0, 0));
	auto* pReadLabel = MenuItemLabel::create(readLabel, this, menu_selector(HelloWorld::readCallback));
	auto* buttonReadLabel = Menu::create(pReadLabel, NULL);
	buttonReadLabel->setPosition(480, 500);
	addChild(buttonReadLabel);

	auto* saveLabel = Label::create("save", "Courier", 56);
	saveLabel->setColor(Color3B(0, 0, 0));
	auto* pSaveLabel = MenuItemLabel::create(saveLabel, this, menu_selector(HelloWorld::saveCallback));
	auto* buttonSaveLabel = Menu::create(pSaveLabel, NULL);
	buttonSaveLabel->setPosition(480, 160);
	addChild(buttonSaveLabel);

	UserDefault::sharedUserDefault()->setBoolForKey("isExisted", false);

	return true;
}
void HelloWorld::readCallback(Ref* pSender)
{
	CCLOG("================================================================");
	std::string path = FileUtils::sharedFileUtils()->getWritablePath() + "test.txt";
	CCLOG("path = %s", path.c_str());
	FILE* file = fopen(path.c_str(), "r");
	if (file)
	{
		char* buf;
		int len;
		fseek(file, 0, SEEK_END);
		len = ftell(file);
		rewind(file);
		CCLOG("count the file content len = %d", len);
		buf = (char*)malloc(sizeof(char)* len + 1);
		if (!buf)
		{
			CCLOG("malloc space is not enough.");
		}
		int rLen = fread(buf, sizeof(char), len, file);
		buf[rLen] = '\0';
		CCLOG("has read Length = %d", rLen);
		CCLOG("has read content = %s", buf);
		fclose(file);
		free(buf);
	}
	else
	{
		CCLOG("open file error.");
	}
	CCLOG("================================================================");
}
void HelloWorld::saveCallback(Ref* pSender)
{
	CCLOG("================================================================");
	std::string path = CCFileUtils::sharedFileUtils()->getWritablePath() + "test.txt";
	FILE* file = fopen(path.c_str(), "w");
	if (file)
	{
		char* pContent = "this is a word";
		fputs(pContent, file);
		CCLOG("save file secceed.");
		fclose(file);
	}
	else
	{
		CCLOG("save file erroe.");
	}
	CCLOG("================================================================");
}
