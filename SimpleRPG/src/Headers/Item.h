#pragma once

#include <string>
#include <map>


class EquippableItem {

public:
	std::string name{};
	short gainAttack, gainDef;
	bool equiped{ false };
	double price;
	std::map<std::string, unsigned> requ{
		{"STR", 0}, {"DEX", 0}
	};

	EquippableItem(std::string _name, short _GAttack, short _GDef);

	void SetReq(short _STR, short _DEX);

};