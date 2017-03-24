//
//  Definition.h
//  UnDefeatedBoss
//
//  Created by Yang Hee.jae on 2016. 12. 2..
//
//

#ifndef Definition_h
#define Definition_h

//== Scene ==//
#define DISPALY_TIME_OF_LOADING_SEQUENCE 1.5f

//== Character ==//
#define PLAYER_STAT_CHECK CCLOG("Player Level : %d", Level );CCLOG("Player Current_Health : %f", Current_Health );CCLOG("Player Max_Health : %f", Max_Health );CCLOG("Player PhysicalPower : %f", PhysicalPower );CCLOG("Player Experience_Current : %f", Experience_Current );CCLOG("Player Experience_Max : %f", Experience_Max );

//STAT BALANCE
#define TEST_PLAYER_STAT_CHANGE Max_Health += 5;PhysicalPower += 1;Experience_Max += 5;

#define ATTACK_AMPLIFIER 1.5f


//== Monster ==//
#define EXPERIENCE_GIVEN_TO_CHARACTER 1.5f //* MonsterLevel

//STAT BALANCE
#define MONSTER_STAT_CHANGE Max_Health += 5;PhysicalPower += 1;

#endif /* Definition_h */
