#pragma once
#include "Monster.h"

class Player {


public:

	short x{}, y{};
	short saved_x{}, saved_y{};
	char PlayerChar{ 'P' };

	Player(short _x = 1, short _y = 1);

	bool Move();

	void Attack(Monster& enemy);

	void TakeDamage(std::string _name, int _damage);

	char BattleOptions();

	bool Death();

	void AddExp(double _exp);

	void LevelUp();

private:

	int damage{ 50 }, hp{ 100 }, lvl{ 1 }, first_levelEXP{ 100 };
	double exp{ 98 }, lup_exp{100}, exp_ratio{ 0.2 };
	
 
};