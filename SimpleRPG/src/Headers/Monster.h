﻿#pragma once
#include <string>

class Monster {


public:
	void printInfo();

	Monster(std::string _name = "None", short _lvl = 0, int _hp = 0, int damage = 0, int armor = 0);

	void TakeDamage(int _hp);

	bool Death();

	int GetDamage();

	std::string GetName();

	double GetExp();

	double GetGMoney();

	void SetPos(short _pos_x, short _pos_y);

	short pos_x{}, pos_y{};

private:
	std::string name{};
	short lvl{};
	int hp{}, damage{}, armor{};
	double gainExp{}, gainMoney{};//change randomly in dependence of level

};