#include "Headers/Item.h"
#include "Headers/Player.h"


EquippableItem::EquippableItem(std::string _name, short _GAttack, short _GDef) {
	this->name = _name;
	this->gainAttack = _GAttack;
	this->gainDef = _GDef;
	this->price = gainAttack + gainDef * 12.5;
}

void EquippableItem::SetReq(short _STR, short _DEX) {
	requ["STR"] = _STR;
	requ["DEX"] = _DEX;
}

