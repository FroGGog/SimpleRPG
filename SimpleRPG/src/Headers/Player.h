#pragma once
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

	void PInfo();

private:

	int damage{ 50 }, hp{ 100 }, lvl{ 1 }, first_levelEXP{ 100 };
	double exp{ 25 }, lup_exp{100}, exp_ratio{ 0.2 };
	
 
};