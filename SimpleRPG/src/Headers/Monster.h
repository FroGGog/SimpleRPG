#pragma once
#include <string>

class Monster {


public:
	void printInfo();

	Monster(std::string _name = "None", short _lvl = 0, int _hp = 0, int damage = 0);

	void TakeDamage(int _hp);

	bool Death();

	int GetDamage();

	std::string GetName();

	double GetExp();



private:
	std::string name{};
	short lvl{};
	int hp{}, damage{};
	double gainExp{25};//change randomly in dependence of level

};