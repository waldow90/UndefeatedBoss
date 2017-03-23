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
    
    //== Battle Phase ==//
    CallFuncN* MonsterHealthCheck = CallFuncN::create( callfunc_selector(GameScene::MonsterAI) );
    DelayTime* DT = DelayTime::create(3.0f);
    
    Spawn* MonsterAI = Spawn::create(DT, MonsterHealthCheck, nullptr);
    RepeatForever* MonsterAI_Repeat = RepeatForever::create(MonsterAI);
    this -> runAction(MonsterAI_Repeat);
    return true;
}

bool GameScene::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    TouchBeganX = touch -> getLocation().x;
    TouchBeganY = touch -> getLocation().y;
    
    //CCLOG("Touch Began");
    
    return true;
}

void GameScene::onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event)
{
    TouchMovedX = touch -> getLocation().x;
    TouchMovedY = touch -> getLocation().y;
    
    //CCLOG("Moved : (%f, %f)", TouchMovedX, TouchMovedY);
}

void GameScene::onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event)
{
    TouchEndedX = touch -> getLocation().x;
    TouchEndedY = touch -> getLocation().y;
    
    //CCLOG("Began : (%f, %f)", TouchBeganX, TouchBeganY);
    //CCLOG("Ended : (%f, %f)", TouchEndedX, TouchEndedY);
    
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
        float C_Damage;
        C_Damage = CharacterSelectScene::Player1.GivePhysicalAttackToMonster(TouchDistance);
        GameScene::SpawnedMonster.SetTakenDamageFromCharacter(C_Damage);
        
        //attack animation
    }
}

void GameScene::MonsterAI()
{
    //check monster health consistantly
    //if monster is dead
    if ( GameScene::SpawnedMonster.IsMonsterKilled() )
    {
        //give experience to the player
        CharacterSelectScene::Player1.GainExperience( GameScene::SpawnedMonster.GetMonsterLevel() );
        //monster level up and re-charge health
        GameScene::SpawnedMonster.MonsterKilled();
        
        return;
    }
    //if monster is alive
    else
    {
        //load monster attack rate
        float MonsterAttackRate = GameScene::SpawnedMonster.GetAttackRate();
        //set delay time = attack time
        DelayTime* M_AttackRate = DelayTime::create( MonsterAttackRate );
        //MonsterAttack
        CallFunc* DoMonsterAttack = CallFuncN::create( callfunc_selector(GameScene::DoMonsterAttack) );
        
        //create action do both
        Spawn* M_Action = Spawn::create(M_AttackRate, DoMonsterAttack, nullptr);
        this -> runAction(M_Action);
    
        return;
    }
}

void GameScene::DoMonsterAttack()
{
    //do the damage
    float M_Damage;
    M_Damage = GameScene::SpawnedMonster.GivePhysicalAttackToCharacter();
    CharacterSelectScene::Player1.SetTakenDamageFromMonster(M_Damage);
    
    //reschedule MonsterAI()
    return;
}


