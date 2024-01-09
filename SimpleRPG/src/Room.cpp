#include "Headers/Room.h"
#include <vector>
#include <iostream>


CurrentRoom::CurrentRoom(short _rows, short _columns) {
		this->rows = _rows;
		this->columns = _columns;
		Room.assign(rows, std::vector<char>(columns, ' '));
	}

void CurrentRoom::ResizeRoom(short _rows, short _columns) {
	this->rows = _rows;
	this->columns = _columns;
	Room.clear();
	Room.assign(rows, std::vector<char>(columns, ' '));

}

void CurrentRoom::PrintRoom() {
	for (short i{ 0 }; i < rows; i++) {
		for (short j{ 0 }; j < columns; j++) {
			if (i == 0 || i == rows - 1) {
				Room[i][j] = '-';
			}
			else if (j == 0 || j == columns - 1) {
				Room[i][j] = '|';
			}
			std::cout << Room[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void CurrentRoom::ChangeRoomCell(short x, short y, char ch) {
	Room[x][y] = ch;
}
