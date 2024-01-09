#include <conio.h>
#include <iostream>

#include "Headers/Player.h"
#include "Headers/Monster.h"


Player::Player(short _x, short _y) {
		this->x = _x;
		this->y = _y;
}


bool Player::Move() {
	if (_kbhit())//check if player pressed any buttons 
	{
		saved_y = y;
		saved_x = x;
		switch (_getch())
		{
		case 'a':
			y -= 1;
			return true;
		case 'd':
			y += 1;
			return true;
		case 'w':
			x -= 1;
			return true;
		case 's':
			x += 1;
			return true;
		case 'q':
			return false;
		default:
			break;
		}
	}
	return false;
}


void Player::Attack(Monster &enemy) {
	enemy.TakeDamage(this->damage);
}


void Player::TakeDamage(std::string _name, int _damage) {
	this->hp -= _damage;
	std::cout << _name + " attacked you and deal " << _damage << " damage. Now you have " << this->hp << " hp\n";
}


char Player::BattleOptions() {

	char choice{};
	std::cout << "\nYou can : \n 1. Melee attack\n 2. Use magic\n 3. Use item from inventory\nType from 1-3\n";
	std::cin >> choice;

	return choice;
}


bool Player::Death() {
	if (this->hp <= 0) {
		return true;
	}
	return false;

}

void Player::AddExp(double _exp)
{
	this->exp += _exp;
}

void Player::LevelUp()
{
	if (this->lvl == 1 && this->exp >= this->lup_exp) {
		this->lvl++;
		this->lup_exp = this->first_levelEXP * (this->lvl--) + this->first_levelEXP * (this->lvl--) * this->exp_ratio;
		std::cout << "\nCongratulation, you have raised your level to the 2!\nPress any button to continue...\n";
		std::cin.get();
	}
	else if(this->exp >= this->lup_exp) {
		this->lvl++;
		this->lup_exp = this->first_levelEXP * (this->lvl--) + this->first_levelEXP * (this->lvl--) * this->exp_ratio;
		std::cout << "\nCongratulation, you have raised your level to the " << this->lvl << "!Press any button to continue...\n";
		std::cin.get();
	}

}



