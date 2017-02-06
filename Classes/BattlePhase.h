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
    class Character
    {
    public:
        //==Stans of Character at battlephase==//
        void GivePhysicalAttackToMonster();
        void GiveMagicalAttackToMonster();
        void DefenseAgainstMonster();
        //take damage from the monster
        void SetTakenDamageFromMonster();
        
        //==STATS OF CHARACTER==//
        int Level;
        //survival
        float Health;
        //physicalDamage
        float PhysicalPower;
        float Weight;
        float AttackRate;
        //magicalDamage
        float MagicalPower;
        float Concentration;
        float Mana;
        
    };
}

#endif /* BattlePhase_h */
