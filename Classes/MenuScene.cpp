//
//  MenuScene.cpp
//  UnDefeatedBoss
//
//  Created by Yang Hee.jae on 2016. 12. 2..
//
//

#include "MenuScene.h"
#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Definition.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool MenuScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    CCLOG( "Entering MenuScene");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    auto menu_item_1 = MenuItemFont::create("Play", CC_CALLBACK_1( MenuScene::Play, this ) );
    auto menu_item_2 = MenuItemFont::create("Settings", CC_CALLBACK_1( MenuScene::Settings, this ) );
    
    menu_item_1 -> setPosition( visibleSize.width/2, visibleSize.height/3 * 2 );
    menu_item_2 -> setPosition( visibleSize.width/2, visibleSize.height/3 * 1 );
    
    auto *menu = Menu::create(menu_item_1,menu_item_2,NULL);
    menu -> setPosition( Point(0,0) );
    this -> addChild(menu);
    
    return true;
}

void MenuScene::Play(cocos2d::Ref *pSender)
{
    auto scene = GameScene::createScene();
    CCLOG("Play");
    Director::getInstance()->replaceScene(TransitionFade::create(DISPALY_TIME_OF_LOADING_SEQUENCE, scene));
}

void MenuScene::Settings(cocos2d::Ref *pSender)
{
    CCLOG("Settings");
}
