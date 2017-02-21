//
//  CharacterSelectScene.cpp
//  UndefeatedBoss
//
//  Created by Yang Hee.jae on 2017. 2. 8..
//
//

#include "CharacterSelectScene.h"
#include "SimpleAudioEngine.h"
#include "Definition.h"
#include "GameScene.h"
#include "BattlePhase.h"

USING_NS_CC;
using namespace BattlePhase;

Scene* CharacterSelectScene::createScene()
{
    auto scene = Scene::create();
    auto layer = CharacterSelectScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool CharacterSelectScene::init()
{
    
    if ( !Layer::init() )
    {
        return false;
    }
    CCLOG( "CharacterSelectScene Entered");
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //test character select slot
    auto CharacterSlot_1 = MenuItemImage::create("Animation/CharacterSelectScene/RedBlock_burned.png"
                                                    , "Animation/CharacterSelectScene/RedBlock_burned.png"
                                                    ,CC_CALLBACK_1(CharacterSelectScene::SelectCharacter_1,this)
                                                     );
    CharacterSlot_1 -> setScale( visibleSize.width/3 / CharacterSlot_1->getContentSize().width
                                    , visibleSize.height / CharacterSlot_1->getContentSize().height );
    CharacterSlot_1 -> setAnchorPoint( Point(0,0) );
    CharacterSlot_1 -> setPosition( origin.x, origin.y);
    
    //Positioning menu node
    auto *menu = Menu::create( CharacterSlot_1,NULL );
    menu -> setPosition( Point(0,0) );
    
    this -> addChild(menu);
    
    return true;
}
//== select a character and go to gamescene ==//
void CharacterSelectScene::SelectCharacter_1(cocos2d::Ref *pSender)
{
    //deliver character name to gamescene
    Player1.SelectCharacter(1);
    
    //Scene transit
    CCLOG("Go To GameScene");
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(DISPALY_TIME_OF_LOADING_SEQUENCE, scene));
}
