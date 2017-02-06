//
//  SettingScene.cpp
//  UndefeatedBoss
//
//  Created by Yang Hee.jae on 2017. 1. 19..
//
//

#include "SettingScene.h"
#include "SimpleAudioEngine.h"
#include "Definition.h"

USING_NS_CC;

Scene* SettingScene::createScene()
{
    auto scene = Scene::create();
    auto layer = SettingScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool SettingScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    CCLOG( "Entering SettingScne");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    return true;
}
