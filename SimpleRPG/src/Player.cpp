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
		case 'q'://quit from game
			return -1;
		case '9':
			return 9;
		case '3'://show player stats
			return 3;
		case '2':
			return 2;
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
	_damage = _damage - rand() % 5;
	double dmgMult = _damage / (_damage + this->defence);
	int damageToDeal = _damage * dmgMult;
	this->hp -= damageToDeal;
	std::cout << _name + " attacked you and deal " << damageToDeal << " damage. Now you have " << this->hp << " hp\n";
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
		std::cout << "\nCongratulation, you have raised your level to 2!\nPress enter to up your stats...\n";
		std::cin.get();
		Player::LevelUpStats();
		Player::UpdateStats();
	}
	else if(this->exp >= this->lup_exp) {
		this->lvl++;
		this->lup_exp = this->first_levelEXP * (this->lvl - 1) + this->first_levelEXP * (this->lvl - 1) * this->exp_ratio;
		std::cout << "\nCongratulation, you have raised your level to " << this->lvl << "!Press enter to up your stats...\n";
		std::cin.get();
		Player::LevelUpStats();
		Player::UpdateStats();
	}

}

void Player::LevelUpStats()
{
	this->lvl_points = 3;
	char choice{};
	std::cout << "Choose wich stat to upgrade (1 - STR, 2 - DEX, 3 - VIT) :\n";
	while (lvl_points > 0) {
		std::cin >> choice;
		switch (choice) {
		case '1':
			this->pStats["STR"]++;
			this->lvl_points--;
			std::cout << "STR is now : " << this->pStats["STR"] << ".Points left -" << lvl_points << '\n';
			break;
		case '2':
			this->pStats["DEX"]++;
			this->lvl_points--;
			std::cout << "DEX is now : " << this->pStats["DEX"] << ".Points left -" << lvl_points << '\n';
			break;
		case '3':
			this->pStats["VIT"]++;
			this->lvl_points--;
			std::cout << "VIT is now : " << this->pStats["VIT"] << ".Points left -" << lvl_points << '\n';
			break;
		default:
			break;
		}
	}
}


void Player::AddHp(short _hp)
{
	this->hp += _hp;
	if (this->hp > this->maxHP) {
		this->hp = maxHP;
	}
}

void Player::UpdateStats()
{
	this->damage = this->basicDamage + this->AddAttack + this->pStats["STR"];
	this->defence = this->basicDefence + this->AddDefence + this->pStats["DEX"] * 0.5;
	this->maxHP = this->maxHP + this->pStats["VIT"] * 3;
}


bool Player::CheckItemFitStats(EquippableItem* ptr)
{
	if (pStats["STR"] >= ptr->requ["STR"]) {
		if (pStats["DEX"] >= ptr->requ["DEX"]) {
			return true;
		}
		return false;
	}
	return false;
}

void Player::PInfo()
{
	system("cls");
	std::cout << "Player\nLvl : " << this->lvl << "\nExp : " << this->exp << " / " << this->lup_exp << '\n';
	std::cout << "Damage - " << this->damage << "\tDefence - " << this->defence << '\n';
	std::cout << "HP - " << this->hp << " / " << this->maxHP << '\n';
	std::cout << "STR - " << this->pStats["STR"] << "  DEX - " << this->pStats["DEX"] << "  VIT - " << this->pStats["VIT"] << '\n';
	std::cout << "Press any button to continue...\n";
}

void Player::FirstPrint() {
	system("cls");
	std::cout << "This is your invontory. (+ - means that item is equiped. Press '2' again to exit)\n";
	std::cout << "Use w/s to go throught inventory. Press E - to equip/un item\n\n";
	for (short i{ 0 }; i < this->EQInv.size(); i++) {
		if (i == 0) {
			std::cout << ">";
		}
		std::cout << i + 1 << ". " << EQInv[i].name << ".  (A | D bonus) = " << EQInv[i].gainAttack << " | " << EQInv[i].gainDef;
		std::cout << "  Req : STR = " << EQInv[i].requ["STR"] << " DEX = " << EQInv[i].requ["DEX"] << "  ";
		std::cout << "\tprice : " << EQInv[i].price << " gold";
		if (EQInv[i].equiped) {
			std::cout << " (E)\n";
			continue;
		}
		std::cout << '\n';
	}
}

void Player::EQInvManager()
{
	EquippableItem* ptr = &EQInv[0];
	bool inInv{ true };
	FirstPrint();
	while (inInv) {
		if (_kbhit()) {
			switch (_getch()) {
			case 'w':
				if (ptr->name == EQInv[0].name) {
					ptr = &EQInv[0];
					break;
				}
				ptr--;
				break;
			case 's':
				if (ptr->name == EQInv[EQInv.size() - 1].name) {
					ptr = &EQInv[EQInv.size() - 1];
					break;
				}
				ptr++;
				break;
			case '2':
				inInv = false;
				Player::UpdateStats();
				std::cout << "Print any button to continue.\n";
				return;
			case 'e':
				if (ptr->equiped) {
					ptr->equiped = false;
					this->AddAttack -= ptr->gainAttack;
					this->AddDefence -= ptr->gainDef;
					break;
				}
				if (Player::CheckItemFitStats(ptr)) {
					ptr->equiped = true;
					this->AddAttack += ptr->gainAttack;
					this->AddDefence += ptr->gainDef;
					break;
				}
				break;
			default:
				break;
			}
			system("cls");
			std::cout << "This is your invontory. (+ - means that item is equiped. Press '2' again to exit)\n";
			std::cout << "Use w/s to go throught inventory. Press E - to equip/un item\n\n";
			for (short i{ 0 }; i < this->EQInv.size(); i++) {
				if (&EQInv[i] == ptr) {
					std::cout << ">";
				}
				std::cout << i + 1 << ". " << EQInv[i].name << ".  (A | D bonus) = " << EQInv[i].gainAttack << " | " << EQInv[i].gainDef;
				std::cout << "  Req : STR = " << EQInv[i].requ["STR"] << " DEX = " << EQInv[i].requ["DEX"] << "  ";
				std::cout << "\tprice : " << EQInv[i].price << " gold";
				if (EQInv[i].equiped) {
					std::cout << " (E)\n";
					continue;
				}
				std::cout << '\n';
			}
		}
	}

}
