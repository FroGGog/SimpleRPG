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
	char PlayerChar{ '\x1E' };

	Player(short _x = 1, short _y = 1);

	short Move(short rows, short columns);

	void Attack(Monster& enemy);

	void TakeDamage(std::string _name, int _damage);

	char BattleOptions();

	bool Death();

	void BattleEnd(double _exp, double _money);

	void LevelUp();

	void EQInvManager();

	void PInfo();

	int GetHp();

	std::vector<EquippableItem> EQInv;

private:

	int damage{ 15 }, hp{ 100 }, lvl{ 1 }, first_levelEXP{ 100 }, maxHP{ 100 };
	int AddDefence{ 0 }, AddAttack{ 0 };
	double exp{ 0 }, lup_exp{ 100 }, exp_ratio{ 0.2 }, defence{ 1 }, money{0};
	short lvl_points{ 0 };
	const int basicDamage{ damage }, basicDefence{ 1 };

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

	bool CheckItemFitStats(EquippableItem* ptr);

	bool CheckItemOnBodyPart(EquippableItem* ptr);

 
};