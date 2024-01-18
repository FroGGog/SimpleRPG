#include <conio.h>
#include <iostream>

#include "Headers/Player.h"


Player::Player(short _x, short _y) {
		this->x = _x;
		this->y = _y;
}


short Player::Move(short rows, short columns) {
	if (_kbhit())//check if player pressed any buttons 
	{
		saved_y = y;
		saved_x = x;
		switch (_getch())
		{
		case 'a':
			y -= 1;
			if (y < 1) {
				y++;
				return 0;
			}
			return 1;
		case 'd':
			y += 1;
			if (y > columns - 2) {
				y--;
				return 0;
			}
			return 1;
		case 'w':
			x -= 1;
			if (x < 1) {
				x++;
				return 0;
			}
			return 1;
		case 's':
			x += 1;
			if (x > rows - 2) {
				x--;
				return 0;
			}
			return 1;
		case 'e':
			return 2;
		case 'q':
			return -1;
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
		this->lup_exp = this->first_levelEXP * (this->lvl - 1) + this->first_levelEXP * (this->lvl - 1) * this->exp_ratio;
		std::cout << "\nCongratulation, you have raised your level to 2!\nPress enter to continue...\n";
		std::cin.get();
	}
	else if(this->exp >= this->lup_exp) {
		this->lvl++;
		this->lup_exp = this->first_levelEXP * (this->lvl - 1) + this->first_levelEXP * (this->lvl - 1) * this->exp_ratio;
		std::cout << "\nCongratulation, you have raised your level to " << this->lvl << "!Press enter to continue...\n";
		std::cin.get();
	}

}

void Player::PInfo()
{
	std::cout << "Player - lvl : " << this->lvl << " exp : " << this->exp << " lvl_up : " << this->lup_exp << '\n';
}





