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
}

void Player::SetCharacterStat()
{
    //allocating character stat
    if( strcmp( Name.getCString() , "Test"))
    {
        Max_Health = 10;
        Currnet_Health = Max_Health;
        PhysicalPower = 1;
    }
}

//confirm character stat and name

cocos2d::__String Player::GetCharacterName()
{
    return Name;
}


//==battle phase function of the character==//
float Player::GivePhysicalAttackToMonster()
{
    //caculating the damage of character onto a monster
    float C_Damage = PhysicalPower;
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



void Monster::SetTakenDamageFromCharacter(float C_Damge)
{
    //take damage from health
    Current_Health -= C_Damge;
    
    if( Current_Health <= 0)
    {
        MonsterKilled();
    }
}
