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
        //confirm character name and stat
        cocos2d::__String GetCharacterName();
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
        int CharacterNumber;
        cocos2d::__String Name;
        //==STATS OF CHARACTER==//
        int Level;
        //survival
        float Currnet_Health;
        float Max_Health;
        //physicalDamage
        float PhysicalPower;
    };
    
    class Monster
    {
    public:
        Monster();
        ~Monster();
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
        int Level;
        //survival
        float Current_Health;
        float Max_Health;
        //physical damage
        float PhysicalPower;
    };
}

#endif /* BattlePhase_h */
