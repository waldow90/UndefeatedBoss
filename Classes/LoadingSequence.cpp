#include "LoadingSequence.h"
#include "MenuScene.h"
#include "Definition.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* LoadingSequence::createScene()
{
    auto scene = Scene::create();
    auto layer = LoadingSequence::create();
    scene->addChild(layer);
    
    return scene;
}

bool LoadingSequence::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    
    //====================== Preload Music =========================================//
    
    //preloading opening hand animation background music
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Animation/OpeningHand/Sound/OpeningHand_SoundOnly.wav");
    
    //====================== Opening Hand Animation ================================//
    
    //set device size variables
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // setting animation
    Sprite *OpeningHand_0 = Sprite::create("Animation/OpeningHand/Image/OpeningHand_1To79_(1).png"); // first appearence
    OpeningHand_0 -> setPosition( visibleSize.width/2 , visibleSize.height/2 + origin.y );
    OpeningHand_0 -> setScale( visibleSize.width / OpeningHand_0->getContentSize().width,
                              visibleSize.height / OpeningHand_0->getContentSize().height );
    this->addChild(OpeningHand_0); // add child to layer
    
    //create animation node
    auto animation = Animation::create();
    
    // setting required variables for animation
    float TotalDisplayLength = 3.78; // length of avi file
    int MaxFrameSize = 79; // target frame size
    float DisplayTimePerFrame = TotalDisplayLength/MaxFrameSize;
    animation -> setDelayPerUnit(DisplayTimePerFrame);
    
    // initiate animation
    for (int i=0; i<MaxFrameSize; i++)
    {
        animation -> addSpriteFrameWithFile(
                    StringUtils::format("Animation/OpeningHand/Image/OpeningHand_1To79_(%d).png", i+1)
                                            );
    }
    auto animate = Animate::create(animation);
    int AnimationRepeatTimes = 1;
    auto action = Repeat::create(animate, AnimationRepeatTimes);
    OpeningHand_0 -> runAction(action);
    
    //setting volume for opening hand animation background music
    CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(1.0);
    // play background music
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Animation/OpeningHand/Sound/OpeningHand_SoundOnly.wav");
    
    // at the end of animation transit scene to menuscene
    this->scheduleOnce(schedule_selector(LoadingSequence::GoToMenuScene), DisplayTimePerFrame*MaxFrameSize*AnimationRepeatTimes );
    
    return true;
} // end of Loading squence init()

//Replace Scene with Menuscene
void LoadingSequence::GoToMenuScene(float dt)
{
    auto scene = MenuScene::createScene();
    CCLOG( "Loading complete");
    Director::getInstance()->replaceScene( TransitionFade::create(DISPALY_TIME_OF_LOADING_SEQUENCE, scene) );
}

/*
//displaying OpeningHand Animation
void LoadingSequence::setAnimation()
{
    //StringUtils::format("Armature-OpeningHand_%02d.png", i)
    
}*/
