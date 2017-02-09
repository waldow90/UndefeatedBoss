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
        void SetCharacterStat(cocos2d::__String CharacterName);
        
        //==Stans of Character at battlephase==//
        float GivePhysicalAttackToMonster();
        //void GiveMagicalAttackToMonster();
        //void DefenseAgainstMonster();
        //take damage from the monster
        void SetTakenDamageFromMonster(float M_Damage);
        
        //==EVENT==//
        //void GainExperience();
        bool LevelUp();
        
        
    protected:
        //==CHARACTER SELECTION==//
        cocos2d::__String Name;
        
        //==STATS OF CHARACTER==//
        int Level = 1;
        //survival
        float Currnet_Health;
        float Max_Health;
        //physicalDamage
        float PhysicalPower;
    };
    
    class Monster
    {
    public:
        //==Stans of Monster at battle phase==//
        float GivePhysicalAttackToCharacter();
        void SetTakenDamageFromCharacter(float C_Damage);
        
        //==Setting the stat of a monster==//
        void MonsterLevelUp();
        
        //==Event==//
        void MonsterKilled();
        
    protected:
        //==Type Of Monster==//
        cocos2d::__String Type;
        
        //==Stats of Monster==//
        int Level = 1;
        //survival
        float Current_Health;
        float Max_Health = 5;
        //physical damage
        float PhysicalPower = 1;
    };
}

#endif /* BattlePhase_h */
