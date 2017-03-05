//
//  BattlePhase.cpp
//  UndefeatedBoss
//
//  Created by Yang Hee.jae on 2017. 2. 6..
//
//

#include "BattlePhase.h"
#include "cocos2d.h"

using namespace BattlePhase;
//==Character Selection==//
//input character name and stat

void Player::SelectCharacter( int SlotNumber )
{
    CharacterNumber = SlotNumber;
    
    if ( CharacterNumber == 1 )
    {
        Name = "Test";
    }
    // comfirming the character name
    CCLOG("Charcater Name : %s", Name.getCString() );
    
}

void Player::SetCharacterStat()
{
    //allocating character stat
    if( strcmp( Name.getCString() , "Test") == 0 ) //strcmp returns 0 when two strings are same
    {
        Level = 1;
        Max_Health = 10;
        Currnet_Health = Max_Health;
        PhysicalPower = 1;
        
        CCLOG("Level : %d, Max_Health : %f, PhysicalPower %f", Level, Max_Health, PhysicalPower);
    }
    
}

//==battle phase function of the character==//
float Player::GivePhysicalAttackToMonster(float BeganTouch = 0,float EndTouch = 0)
{
    
    //caculating the damage of character onto a monster
    float C_Damage = PhysicalPower;
    CCLOG("Give Damage To Monster By : %f", C_Damage);
    return C_Damage;
}

void Player::SetTakenDamageFromMonster(float M_Damage)
{
    //take damage from health
    Currnet_Health -= M_Damage;
}

bool Player::LevelUp()
{
    Level += 1;
    
    //==character stat upgrades differ with character classes==//
    
    // 1. Test
    if( strcmp( Name.getCString() , "Test"))
    {
        Max_Health += 5;
        PhysicalPower += 1;
    }
    
    return true;
}

//==Events assoiated with Monster==//
void Monster::MonsterLevelUp()
{
    //increase level of monster
    Level += 1;
    
    //upgrade maxhealth of monster
    Max_Health += 5;
    PhysicalPower += 1;
}

void Monster::MonsterKilled()
{
    Monster::MonsterLevelUp();
    
    //reset monster health to full
    Current_Health = Monster::Max_Health;
}

//==battle phase function of a monster==//
float Monster::GivePhysicalAttackToCharacter()
{
    //caculating the damage of a monster onto the charater
    float M_Damage = Monster::PhysicalPower;
    return M_Damage;
}



void Monster::SetTakenDamageFromCharacter(float C_Damage)
{
    //take damage from health
    Current_Health -= C_Damage;
    CCLOG("Monster Damage Taken By : %f", C_Damage);
    
    if( Current_Health <= 0)
    {
        MonsterKilled();
        CCLOG("Monster Killed");
    }
}
