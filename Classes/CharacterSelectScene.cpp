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
    auto TestCharacterSelect = MenuItemImage::create("Animation/CharacterSelectScene/RedBlock_burned.png"
                                                    , "Animation/CharacterSelectScene/RedBlock_burned.png"
                                                    ,CC_CALLBACK_1(CharacterSelectScene::SelectCharacter_Test,this)
                                                     );
    TestCharacterSelect -> setScale( visibleSize.width/3 / TestCharacterSelect->getContentSize().width
                                    , visibleSize.height / TestCharacterSelect->getContentSize().height );
    TestCharacterSelect -> setAnchorPoint( Point(0,0) );
    TestCharacterSelect -> setPosition( origin.x, origin.y);
    
    this -> addChild(TestCharacterSelect);
    
    return true;
}
//== select a character and go to gamescene ==//
void CharacterSelectScene::SelectCharacter_Test(cocos2d::Ref *pSender)
{
    //deliver character name to gamescene
    CharacterName = "Test";
    
    //Scene transit
    CCLOG("Go To GameScene");
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(TransitionFade::create(DISPALY_TIME_OF_LOADING_SEQUENCE, scene));
}
