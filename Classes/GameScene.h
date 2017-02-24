//
//  GameScene.hpp
//  UnDefeatedBoss
//
//  Created by Yang Hee.jae on 2016. 12. 2..
//
//

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "BattlePhase.h"

using namespace BattlePhase;

class GameScene : public cocos2d::Layer
{
public:
    //==Functions needed to Create and Init the Scene==//
    static cocos2d::Scene* createScene();
    virtual bool init();
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
    //==Assosiated with Touch==//
    bool onTouchBegan( cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchMoved( cocos2d::Touch* touch, cocos2d::Event* event);
    void onTouchEnded( cocos2d::Touch* touch, cocos2d::Event* event);
    //Touched Location
    float TouchBeganX, TouchBeganY;
    float TouchMovedX, TouchMovedY;
    float TouchEndedX, TouchEndedY;
    //== Variables for Battle ==//
    //create Monster Class
    Monster SpawnedMonster;
    
};

#endif // __GAME_SCENE_H__
