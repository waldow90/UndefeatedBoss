//
//  MenuScene.cpp
//  UnDefeatedBoss
//
//  Created by Yang Hee.jae on 2016. 12. 2..
//
//

#include "MenuScene.h"
#include "CharacterSelectScene.h"
#include "SimpleAudioEngine.h"
#include "Definition.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool MenuScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    //Start of MenuScene
    CCLOG( "Entering MenuScene");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //create MenuItems with sprite
    auto menu_item_play = MenuItemImage::create("Animation/MenuScene/PlayButton/PlayButton_(1).png"
                                                , "Animation/MenuScene/PlayButton/PlayButton_(30).png"
                                                , CC_CALLBACK_1( MenuScene::Play, this ));
    

    auto menu_item_setting = MenuItemImage::create("Animation/MenuScene/SettingButton/SettingButton_1To30_(1).png"
                                                , "Animation/MenuScene/SettingButton/SettingButton_1To30_(30).png"
                                                , CC_CALLBACK_1( MenuScene::Settings, this ));
    
    //allocating sprite menu
    menu_item_play -> setPosition( visibleSize.width/2, visibleSize.height/3 * 2 );
    menu_item_play -> setScale( visibleSize.width/5 / menu_item_play->getContentSize().width
                               , visibleSize.height/4 / menu_item_play->getContentSize().height );
    
    menu_item_setting -> setPosition( visibleSize.width/2, visibleSize.height/3 * 1 );
    menu_item_setting -> setScale( visibleSize.width/5 / menu_item_play->getContentSize().width
                               , visibleSize.height/4 / menu_item_play->getContentSize().height );
    
    //Positioning menu node
    auto *menu = Menu::create(menu_item_play,menu_item_setting,NULL);
    menu -> setPosition( Point(0,0) );
    
    /*
    //create animation node
    auto animation = Animation::create();
    
    // setting required variables for animation
    float TotalDisplayLength = 1.25; // length of avi file
    int MaxFrameSize = 30; // target frame size
    float DisplayTimePerFrame = TotalDisplayLength/MaxFrameSize;
    animation -> setDelayPerUnit(DisplayTimePerFrame);
    
    // initiate animation
    for (int i=0; i<MaxFrameSize; i++)
    {
        animation -> addSpriteFrameWithFile(
                                            StringUtils::format("Animation/MenuScene/PlayButton/PlayButton_(%d).png", i+1)
                                            );
    }
    auto animate = Animate::create(animation);
    auto action = RepeatForever::create(animate);
    menu_item_play -> runAction(action);
    */
    this -> addChild(menu);
    
    
    return true;
}

void MenuScene::Play(cocos2d::Ref *pSender)
{
    CCLOG("Go To CharacterSelect");
    auto scene = CharacterSelectScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(DISPALY_TIME_OF_LOADING_SEQUENCE, scene));
}

void MenuScene::Settings(cocos2d::Ref *pSender)
{
    CCLOG("Settings");
}
