#include "Headers/Item.h"


HealPotion::HealPotion(short _count, short _price, int _heal_value) {
	this->count = _count;
	this->price = _price;
	this->heal_value = _heal_value;
}

void HealPotion::heal(Player& player)
{
	player.AddHp(this->heal_value);
}

EquippableItem::EquippableItem(std::string _name, short _GAttack, short _GDef) {
	this->name = _name;
	this->gainAttack = _GAttack;
	this->gainDef = _GDef;
	this->price = gainAttack + gainDef * 12.5;
}

void EquippableItem::SetReq(short _STR, short _DEX, short _INT) {
	requirements["STR"] = _STR;
	requirements["DEX"] = _DEX;
	requirements["INT"] = _INT;
}

