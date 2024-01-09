#pragma once
#include <vector>

class CurrentRoom {

public:

	CurrentRoom(short _rows, short _columns);

	void ResizeRoom(short _rows, short _columns);

	void PrintRoom();

	void ChangeRoomCell(short x, short y, char ch);

private:
	short rows, columns;

	std::vector<std::vector<char>> Room;

};