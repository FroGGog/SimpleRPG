#include <iostream>
#include <vector>
#include <conio.h>

#include "Headers/Room.h"


class Player {

public:
	short x{}, y{};
	short saved_x{}, saved_y{};
	char PlayerChar{ 'P' };

	Player(short _x = 1, short _y = 1) {
		this->x = _x;
		this->y = _y;
	}

	bool Move() {
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

};



int main() {
	
	CurrentRoom Room{10, 10};
	Player player{};
	Room.ChangeRoomCell(player.x, player.y, player.PlayerChar);
	while (true) {
		if (player.Move()) {
			system("cls");
			Room.ChangeRoomCell(player.x, player.y, player.PlayerChar);
			Room.ChangeRoomCell(player.saved_x, player.saved_y, ' ');
			Room.ChangeRoomCell(2, 2, 'D');
			Room.PrintRoom();
		}
	}
	




}