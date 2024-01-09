#include <iostream>
#include "Headers/Monster.h"


void Monster::printInfo() {
	std::cout << "You met " + name + '\n' << "His level is " << lvl << '\n' << "He got " << hp << " hp\n";
}


Monster::Monster(std::string _name, short _lvl, int _hp, int _damage) {
	this->name = _name;
	this->lvl = _lvl;
	this->hp = _hp;
	this->damage = _damage;
}


void Monster::TakeDamage(int _hp) {
	this->hp -= _hp;
	std::cout << "You deal " << _hp << " damage to " + this->name << ". Now he got " << this->hp << " hp\n";
}


bool Monster::Death() {
	if (this->hp <= 0) {
		return true;
	}
	return false;
}


int Monster::GetDamage() {
	return this->damage;
}


std::string Monster::GetName() {
	return this->name;
}

double Monster::GetExp()
{
	return this->gainExp;
}
