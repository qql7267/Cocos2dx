#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "tinyxml2/tinyxml2.h"
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
    
	std::string filename = "test.xml";
	tinyxml2::XMLDocument* pDoc = new tinyxml2::XMLDocument();
	tinyxml2::XMLDeclaration* pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
	pDoc->LinkEndChild(pDel);

	tinyxml2::XMLElement* rootElement = pDoc->NewElement("xmlRoot");
	rootElement->SetAttribute("version", "1.0");
	pDoc->LinkEndChild(rootElement);

	tinyxml2::XMLComment* commentElement = pDoc->NewComment("this is xml comment");
	rootElement->LinkEndChild(commentElement);

	for (int i = 0; i < 20; i++)
	{
		tinyxml2::XMLElement* myElement = pDoc->NewElement("node");
		myElement->SetAttribute("id", i);
		myElement->SetAttribute("type", "Cocos2d");
		rootElement->LinkEndChild(myElement);
	}
	pDoc->SaveFile(filename.c_str());
	pDoc->Print();
	delete pDoc;

    return true;
}
