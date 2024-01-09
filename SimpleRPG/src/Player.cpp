#include <conio.h>

#include "Headers/Player.h"

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
