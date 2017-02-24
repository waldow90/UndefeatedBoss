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
    //== Base of GameScene init ==//
    if ( !Layer::init() )
    {
        return false;
    }
    CCLOG( "GameScene Entered");
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //== touch listenter ==//
    //touch listener
    auto listener = EventListenerTouchOneByOne::create();
    listener -> setSwallowTouches(true);
    //on touch began
    listener -> onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    listener -> onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);
    listener -> onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);
    _eventDispatcher -> addEventListenerWithSceneGraphPriority(listener, this);
    
    
    //== Character Stat ==//
    //load and set character stat
    CharacterSelectScene::Player1.SetCharacterStat();
    // comfirming the character name
    CCLOG("Charcater Name : %s", CharacterSelectScene::Player1.GetCharacterName().getCString() );
    
    //==Monseter Stat ==//
    
    
    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    TouchBeganX = touch -> getLocation().x;
    TouchBeganY = touch -> getLocation().y;
    
    CCLOG("Began : (%f, %f)", TouchBeganX, TouchBeganY);
    
    return true;
}

void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    TouchMovedX = touch -> getLocation().x;
    TouchMovedY = touch -> getLocation().y;
    
    CCLOG("Moved : (%f, %f)", TouchMovedX, TouchMovedY);
}

void GameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    TouchEndedX = touch -> getLocation().x;
    TouchEndedY = touch -> getLocation().y;
    
    CCLOG("Ended : (%f, %f)", TouchEndedX, TouchEndedY);
}
