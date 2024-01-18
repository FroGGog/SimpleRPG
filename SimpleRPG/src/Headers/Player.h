#pragma once
#include "Monster.h"
#include <vector>
#include <map>
#include <string>

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

	void AddHp(short _hp);

	void UpdateStats();

	void LevelUpStats();

	void PInfo();

	std::map<std::string, int> pStats{
		{"STR", 1}, {"DEX", 1}, {"INT", 1}
	};

private:

	int damage{ 25 }, hp{ 100 }, lvl{ 1 }, first_levelEXP{ 100 }, maxHP{ 100 };
	int AddDefence{ 0 }, AddAttack{};
	double exp{ 25 }, lup_exp{100}, exp_ratio{ 0.2 }, defence{ 1 };
	short lvl_points{ 0 };
	
 
};