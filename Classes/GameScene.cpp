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

using namespace BattlePhase;
USING_NS_CC;
//static class declare
Player CharacterSelectScene::Player1;

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
    CCLOG( "GameScene Entered");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //== Character Stat ==//
    //Player* Player1 = new Player(); //create class of player
    // comfirming the character name
    
    CCLOG("Charcater Name : %s", CharacterSelectScene::Player1.GetCharacterName().getCString() );
    //setting inital selected character stat
    
    //==Monseter Stat ==//
    
    
    return true;
}
