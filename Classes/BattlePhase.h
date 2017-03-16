//
//  BattlePhase.h
//  UndefeatedBoss
//
//  Created by Yang Hee.jae on 2017. 2. 6..
//
//

#ifndef BattlePhase_h
#define BattlePhase_h

#include "cocos2d.h"

namespace BattlePhase {
    
    //Interactions of character at battlephase
    class Player
    {
    public:
        //==character selection==//
        //input character name and stat
        void SelectCharacter( int SlotNumber );
        void SetCharacterStat();
        //==Stans of Character at battlephase==//
        float GivePhysicalAttackToMonster(float TouchDistance);
        //void GiveMagicalAttackToMonster();
        //void DefenseAgainstMonster();
        //take damage from the monster
        void SetTakenDamageFromMonster(float M_Damage);
        //==EVENT==//
        void GainExperience( int MonsterLevel );
        bool LevelUp();
        
    protected:
        //==CHARACTER SELECTION==//
        int CharacterNumber;
        cocos2d::__String Name;
        //==STATS OF CHARACTER==//
        int Level;
        float Experience_Max;
        float Experience_Current;
        
        //survival
        float Currnet_Health;
        float Max_Health;
        //physicalDamage
        float PhysicalPower;
        //==ATTACK OF CHARACTER==//
    };
    
    class Monster
    {
    public:
        //==Stans of Monster at battle phase==//
        float GivePhysicalAttackToCharacter();
        void SetTakenDamageFromCharacter(float C_Damage);
        //==Setting the stat of a monster==//
        void MonsterLevelUp();
        int GetMonsterLevel();
        //==Event==//
        bool MonsterKilled();
    protected:
        //==Type Of Monster==//
        cocos2d::__String Type;
        //==Stats of Monster==//
        int Level = 1;
        //survival
        float Current_Health = 5;
        float Max_Health = 5;
        //physical damage
        float PhysicalPower = 1;
    };
}

#endif /* BattlePhase_h */
