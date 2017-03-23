//
//  BattlePhase.cpp
//  UndefeatedBoss
//
//  Created by Yang Hee.jae on 2017. 2. 6..
//
//

#include "BattlePhase.h"
#include "cocos2d.h"
//for valance
#include "Definition.h"

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
        Current_Health = Max_Health;
        PhysicalPower = 1;
        
        PLAYER_STAT_CHECK;
        
    }
    
    return;
}

//==battle phase function of the character==//
float Player::GivePhysicalAttackToMonster(float TouchDistance)
{
    //do physical attack
    //load amplifier
    float Amplifier = ATTACK_AMPLIFIER;
    //times with touchdistance
    Amplifier *= TouchDistance;
    //caculating the damage of character onto a monster
    float C_Damage = PhysicalPower * Amplifier;
    CCLOG("Give Damage To Monster By : %f", C_Damage);
    
    return C_Damage;
}

void Player::SetTakenDamageFromMonster(float M_Damage)
{
    //take damage from health
    Current_Health -= M_Damage;
    CCLOG("Character Damage Taken By : %f", M_Damage);
    CCLOG("Current Character Health : %f", Current_Health);
    return;
}

//== Stat Assosiated Functions in battle phase ==//
bool Player::LevelUp()
{
    Level += 1;
    CCLOG("Character Level UP");
    //==character stat upgrades differ with character classes==//
    
    // 1. Test
    if( !strcmp( Name.getCString() , "Test") )// if text is matched strcmp returns 0
    {
        Max_Health += 5;
        //restore health to full
        Current_Health = Max_Health;
        PhysicalPower += 1;
        Experience_Max += 5;
    }
    
    PLAYER_STAT_CHECK;
    
    return true;
}

void Player::GainExperience(int MonsterLevel)
{
    //load experience amplifier
    float GivenExperience = EXPERIENCE_GIVEN_TO_CHARACTER;
    //give experience to character
    Experience_Current += GivenExperience*MonsterLevel;
    CCLOG("Current Experience : %f", Experience_Current);
    
    if ( Experience_Current >= Experience_Max )
    {
        LevelUp();
    }
    return;
}

//==Events assoiated with Monster in battle phase==//
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

bool Monster::IsMonsterKilled()
{
    if ( Current_Health > 0 )
    {
        //CCLOG("Monster Health Check : %f", Current_Health);
        return false;
    }
    else
    {
        return true;
    }
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
    CCLOG("Give Character Damage By : %f", M_Damage);
    return M_Damage;
}

float Monster::GetAttackRate()
{
    float AR = AttackRate;
    return AR;
}

void Monster::SetTakenDamageFromCharacter(float C_Damage)
{
    //take damage from health
    Current_Health -= C_Damage;
    CCLOG("Monster Damage Taken By : %f", C_Damage);
    CCLOG("Current Monster Health : %f", Current_Health);
    
}
