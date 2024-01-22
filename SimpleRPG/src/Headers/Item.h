#pragma once

#include <string>
#include <map>


class EquippableItem {

public:
	std::string name{}, bodyPart{};
	short gainAttack, gainDef;
	bool equiped{ false };
	double price;
	std::map<std::string, int> requ{
		{"STR", 0}, {"DEX", 0}
	};

	EquippableItem(std::string _name, short _GAttack, short _GDef);

	void SetReq(short _STR, short _DEX);

};