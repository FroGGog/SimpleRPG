#pragma once
#include <vector>
#include "Monster.h"
#include "Player.h"

class CurrentRoom {

public:

	CurrentRoom();

	void PrintRoom();

	void CreateRoom();

	char GetCell(short x, short y);

	void ChangeRoomCell(short x, short y, char ch);

	short SearchEnemy(Player &player);

	void Info();

	std::vector<Monster> EnemiesInRoom;

	short rows, columns;


private:
	short c_enemies{ 0 }, c_chest{ 0 }, c_door{ 0 };

	std::vector<std::vector<char>> Room;

	void ObjectsNumGen();

	void ResizeRoom();

	void GetChestPos();

	void GetEnemiesPos();

};