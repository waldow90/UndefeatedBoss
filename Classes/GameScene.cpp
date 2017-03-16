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
Monster GameScene::SpawnedMonster;

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
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    
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
    //==Monseter Stat ==//
    
    /*
    //== Battle Phase ==//
    //Monster Killed
    if ( GameScene::SpawnedMonster.MonsterKilled() )
    {
        CharacterSelectScene::Player1.GainExperience( GameScene::SpawnedMonster.GetMonsterLevel() );
    }
    */
    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    TouchBeganX = touch -> getLocation().x;
    TouchBeganY = touch -> getLocation().y;
    
    CCLOG("Touch Began");
    
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
    
    CCLOG("Began : (%f, %f)", TouchBeganX, TouchBeganY);
    CCLOG("Ended : (%f, %f)", TouchEndedX, TouchEndedY);
    
    //calculate multiplyer
    float TouchDistance = sqrtf( powf((TouchBeganX - TouchEndedX)/visibleSize.width, 2)
                                + powf( (TouchBeganY - TouchEndedY)/visibleSize.height, 2) );
    CCLOG("Distance : %f", TouchDistance);
    
    //cast a spell
    if( TouchDistance < 0.05 ) //if there is no drag
    {
        CCLOG("Need to Make Spell");
        return;
    }
    //do physical Damage
    else
    {
        //when touch ended damage function began
        float Damage;
        Damage = CharacterSelectScene::Player1.GivePhysicalAttackToMonster(TouchDistance);
        GameScene::SpawnedMonster.SetTakenDamageFromCharacter(Damage);
        
        //attack animation
    }
    
    
}
