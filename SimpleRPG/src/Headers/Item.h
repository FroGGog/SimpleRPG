#pragma once

#include <string>
#include <map>
#include "Player.h"


class HealPotion {

public:

	bool consumable{ true };
	std::string name{ "Heal potion" };
	short count, price;
	int heal_value{};

	HealPotion(short _count, short _price, int _heal_value);

	void heal(Player &player);

};

class EquippableItem {

public:
	std::string name{};
	short price, gainAttack, gainDef;
	bool equiped{ false };
	std::map<std::string, unsigned> requirements;

	EquippableItem(std::string _name, short _GAttack, short _GDef);

	void SetReq(short _STR, short _DEX, short _INT);

};