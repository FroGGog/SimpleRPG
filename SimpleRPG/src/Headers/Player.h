#pragma once

#include <vector>
#include <map>
#include <string>
#include "Item.h"
#include "Monster.h"

class Player {


public:

	short x{}, y{};
	short saved_x{}, saved_y{};
	char PlayerChar{ 'P' };

	Player(short _x = 1, short _y = 1);

	short Move(short rows, short columns);

	void Attack(Monster& enemy);

	void TakeDamage(std::string _name, int _damage);

	char BattleOptions();

	bool Death();

	void AddExp(double _exp);

	void LevelUp();

	void EQInvManager();

	void PInfo();

	std::vector<EquippableItem> EQInv;

private:

	int damage{ 25 }, hp{ 500 }, lvl{ 1 }, first_levelEXP{ 100 }, maxHP{ 1000 };
	int AddDefence{ 0 }, AddAttack{};
	double exp{ 25 }, lup_exp{100}, exp_ratio{ 0.2 }, defence{ 1 };
	short lvl_points{ 0 };

	std::map<std::string, bool> EqpItems{

		{"Head", false}, {"Chest", false}, {"Legs", false},
		{"Foots", false}, {"Arms", false}, {"RHand", false},
		{"LHand", false}, {"Neck", false}

	};

	std::map<std::string, int> pStats{
	{"STR", 1}, {"DEX", 1}, {"VIT", 1}
	};
	
	void FirstPrint();

	void AddHp(short _hp);

	void UpdateStats();

	void LevelUpStats();

 
};