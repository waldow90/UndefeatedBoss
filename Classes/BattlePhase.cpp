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
 
    return;
}

void Player::SetCharacterStat()
{
    //allocating character stat
    if( strcmp( Name.getCString() , "Test") == 0 ) //strcmp returns 0 when two strings are same
    {
        //Level
        Level = 1;
        Experience_Max = 1;
        Experience_Current = 0;
        
        //Stats
        Max_Health = 10;
        Currnet_Health = Max_Health;
        PhysicalPower = 1;
        
        CCLOG("Level : %d, Max_Health : %f, PhysicalPower %f", Level, Max_Health, PhysicalPower);
    }
    
    return;
}

//==battle phase function of the character==//
float Player::GivePhysicalAttackToMonster(float TouchDistance)
{
    //do physical attack
    float Amplifyer = 1.5*TouchDistance;
    //caculating the damage of character onto a monster
    float C_Damage = PhysicalPower * Amplifyer;
    CCLOG("Give Damage To Monster By : %f", C_Damage);
    
    return C_Damage;
}

void Player::SetTakenDamageFromMonster(float M_Damage)
{
    //take damage from health
    Currnet_Health -= M_Damage;
    
    return;
}

//== Stat Assosiated Functions ==//
bool Player::LevelUp()
{
    Level += 1;
    Experience_Max += 5;
    
    //==character stat upgrades differ with character classes==//
    
    // 1. Test
    if( strcmp( Name.getCString() , "Test"))
    {
        Max_Health += 5;
        PhysicalPower += 1;
    }
    
    return true;
}

void Player::GainExperience(int MonsterLevel)
{
    
    Experience_Current += 1.5*MonsterLevel;
    
    return;
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

int Monster::GetMonsterLevel()
{
    CCLOG("Monster Level : %d", Level);
    return Level;
}

bool Monster::MonsterKilled()
{
    //monster level up
    Monster::MonsterLevelUp();
    
    //reset monster health to full
    Current_Health = Monster::Max_Health;
    
    return true;
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
    CCLOG("Current Monster Health : %f", Current_Health);
    if( Current_Health <= 0)
    {
        CCLOG("Monster Killed");
        MonsterKilled();
    }
}
