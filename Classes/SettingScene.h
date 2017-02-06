//
//  SettingScene.hpp
//  UndefeatedBoss
//
//  Created by Yang Hee.jae on 2017. 1. 19..
//
//

#ifndef SettingScene_hpp
#define SettingScene_hpp

#include "cocos2d.h"

class SettingScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(SettingScene);
    
    //sprite
    cocos2d::Sprite *backgroundSprite;
    
    
};


#endif /* SettingScene_hpp */
