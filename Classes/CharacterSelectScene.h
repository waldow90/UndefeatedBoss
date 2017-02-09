//
//  CharacterSelectScene.hpp
//  UndefeatedBoss
//
//  Created by Yang Hee.jae on 2017. 2. 8..
//
//

#ifndef __CHARACTER_SELECT_SCENE_H__
#define __CHARACTER_SELECT_SCENE_H__

#include "cocos2d.h"

class CharacterSelectScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(CharacterSelectScene);
    
    //sprite
    cocos2d::Menu *TestCharacterSelect;
    
    //character select
    void SelectCharacter_Test(Ref *pSender);
    static cocos2d::__String CharacterName;
    
};

#endif // __CHARACTER_SELECT_SCENE_H__