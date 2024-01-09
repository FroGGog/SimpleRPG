#include <iostream>
#include <chrono>

#include "Headers/Room.h"
#include "Headers/Player.h"

const double FPS{ 0.05 };

//Update screen time calculation
bool TimeUpdate(std::chrono::system_clock::time_point t_start) {

	std::chrono::duration<float> UPDTime{ std::chrono::system_clock::now() - t_start };

	return UPDTime.count() > ::FPS;

}

class Monster {




};



int main() {

	auto t_start{ std::chrono::system_clock::now() };
	
	CurrentRoom Room{10, 25};
	Player player{};
	//Changes room cell on pos x,y with given char
	Room.ChangeRoomCell(player.x, player.y, player.PlayerChar);
	Room.PrintRoom();
	while (true) {
		//if it's time to update we can move and do stuff
		if (TimeUpdate(t_start)) {
			if (player.Move()) {
				system("cls");
				t_start = std::chrono::system_clock::now();
				Room.ChangeRoomCell(player.x, player.y, player.PlayerChar);
				Room.ChangeRoomCell(player.saved_x, player.saved_y, ' ');
				Room.PrintRoom();
			}
		}
	}
	




}