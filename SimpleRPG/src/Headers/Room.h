#pragma once
#include <vector>

class CurrentRoom {

public:

	CurrentRoom(short _rows, short _columns);

	void ResizeRoom(short _rows, short _columns);

	void PrintRoom();

	void ChangeRoomCell(short x, short y, char ch);

	bool StartBattle(short p_x, short p_y);

private:
	short rows, columns;

	std::vector<std::vector<char>> Room;

};