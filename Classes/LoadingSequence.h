#ifndef __LOADING_SEQUENCE_H__
#define __LOADING_SEQUENCE_H__

#include "cocos2d.h"

class LoadingSequence : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(LoadingSequence);
    
    //sprite
    cocos2d::Sprite *backgroundSprite;
    
    //go to menu scene
    void GoToMenuScene(float dt);
    
    
    //Adding Animation
    //Showing Animaiton (Logo) while loading sound effects
    //Logo image file
    void setAnimation();
    
    
};

#endif // __LOADING_SEQUENCE_
