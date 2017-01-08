//
//  GameScene.cpp
//  UnDefeatedBoss
//
//  Created by Yang Hee.jae on 2016. 12. 2..
//
//

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "Definition.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool GameScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    CCLOG( "Entering GameScne");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    return true;
}
