#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "curl/include/win32/curl/curl.h"
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
    
	curl_global_init(CURL_GLOBAL_ALL);
	CURL* curl = curl_easy_init();
	curl_easy_setopt(curl, CURLOPT_URL, "http://www.iqiyi.com/");
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, info_output);
	CURLcode success = curl_easy_perform(curl);
	curl_global_cleanup();

    return true;
}
size_t HelloWorld::info_output(void* buffer, size_t size, size_t nmemb, void *userp)
{
	CCLOG("===============================================================");
	CCLOG("%s", buffer);
	CCLOG("===============================================================");
	return 0;
}
