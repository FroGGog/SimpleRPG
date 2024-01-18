#include "Headers/Room.h"
#include "Headers/Player.h"
#include <iostream>


CurrentRoom::CurrentRoom() {
	CurrentRoom::CreateRoom();
}


void CurrentRoom::ResizeRoom() {
	this->roomDeep++;
	this->rows = rand() % 15 + 5;
	this->columns = rand() % 20 + 5;
	Room.clear();
	Room.assign(rows, std::vector<char>(columns, ' '));

}


void CurrentRoom::PrintRoom() {
	for (short i{ 0 }; i < this->rows; i++) {
		for (short j{ 0 }; j < this->columns; j++) {
			if (i == 0 || i == this->rows - 1) {
				Room[i][j] = '-';
			}
			else if (j == 0 || j == this->columns - 1) {
				Room[i][j] = '|';
			}
			std::cout << Room[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void CurrentRoom::GetChestPos()
{
	short pos_x{}, pos_y{};
	pos_x = rand() % (this->rows - 1) + 1;
	pos_y = rand() % (this->columns - 1) + 1;
	CurrentRoom::ChangeRoomCell(pos_x, pos_y, 'D');
}


void CurrentRoom::GetEnemiesPos()
{
	EnemiesInRoom.clear();
	short pos_x{}, pos_y{};
	while (this->c_enemies > 0) {

		pos_x = rand() % (this->rows - 2) + 1;
		pos_y = rand() % (this->columns - 2) + 1;

		if (Room[pos_x][pos_y] == ' ') {
			CurrentRoom::ChangeRoomCell(pos_x, pos_y, 'E');
			short enemyLevel = rand() % (this->roomDeep) + 1;
			short enemyHp = (enemyLevel * 25) - (rand() % (enemyLevel * 25 / 10) + 1);
			short enemyDamage = (enemyHp / enemyLevel) - (rand() % (int)25 / enemyLevel);
			short enemyArmor = enemyLevel + rand() % enemyLevel + 1;
			Monster temp_enemy{ "Snake", enemyLevel, enemyHp, enemyDamage, 0};
			temp_enemy.SetPos(pos_x, pos_y);
			CurrentRoom::EnemiesInRoom.push_back(temp_enemy);
			this->c_enemies--;
		}
	}


}



void CurrentRoom::CreateRoom()
{
	
	CurrentRoom::ResizeRoom();
	CurrentRoom::ObjectsNumGen();

	if (this->c_chest) {
		CurrentRoom::GetChestPos();
	}

	CurrentRoom::GetEnemiesPos();

}

char CurrentRoom::GetCell(short x, short y)
{
	return CurrentRoom::Room[x][y];

}

void CurrentRoom::ObjectsNumGen()
{
	this->c_chest = rand() % 100;
	if (this->c_chest < 15) {
		this->c_chest = 1;
	}
	else {
		this->c_chest = 0;
	}

	this->c_door = rand() % 4 + 1;

	this->c_enemies = rand() % 5 + 1;

}


void CurrentRoom::ChangeRoomCell(short x, short y, char ch) {
	Room[x][y] = ch;
}


short CurrentRoom::SearchEnemy(Player& player) {
	for (short i{ 0 }; i < CurrentRoom::EnemiesInRoom.size(); i++) {
		if (player.x == CurrentRoom::EnemiesInRoom[i].pos_x && player.y == CurrentRoom::EnemiesInRoom[i].pos_y) {
			return i;
		}
	}
}

void CurrentRoom::Info()
{
	std::cout << "Chest : " << this->c_chest << " enemies : " << this->EnemiesInRoom.size() << " doors : " << this->c_door << '\n';

}
