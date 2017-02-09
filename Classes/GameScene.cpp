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
#include "BattlePhase.h"
//the selected character name is delivered
#include "CharacterSelectScene.h"

cocos2d::__String CharacterSelectScene::CharacterName; //given character name static variable

using namespace BattlePhase;
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
    CCLOG( "CharacterSelectScene Entered");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //setting inital selected character stat
    Player Player1;
    Player1.SetCharacterStat( CharacterSelectScene::CharacterName );
    
    return true;
}
