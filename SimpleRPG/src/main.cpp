#include <chrono>
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <string>

#include "Headers/Room.h"
#include "Headers/Item.h"

const double FPS{ 0.05 };

//Update screen time calculation
bool TimeUpdate(std::chrono::system_clock::time_point t_start) {

	std::chrono::duration<float> UPDTime{ std::chrono::system_clock::now() - t_start };

	return UPDTime.count() > ::FPS;

}


bool Battle(Player& player, Monster& enemy) {
	char choice{};
	enemy.printInfo();
	while (!player.Death() && !enemy.Death()) {
		choice = player.BattleOptions();
		system("cls");
		switch (choice)
		{
		case '1':
			player.Attack(enemy);
		default:
			break;
		}
		if (enemy.Death()) {
			break;
		}
		else {
			player.TakeDamage(enemy.GetName(), enemy.GetDamage());
		}
		
	}
	if (player.Death()) {
		std::cout << "\nX_X You dead X_X\n";
		return false;
	}
	else if (enemy.Death()) {
		std::cout << "\nYou won! You got " << enemy.GetExp() << " xp\n";
		std::cout << "Press enter to continue...\n";
		player.AddExp(enemy.GetExp());
		std::cin.ignore();
		std::cin.get();
		return true;
	}
}

void LoadingScreen() {
	system("cls");
	for (short i{ 1 }; i < 5; i++) {
		std::cout << "Loading new room" << std::string(i, '.');
		Sleep(500);
		system("cls");
	}
	
}


int main() {

	auto t_start{ std::chrono::system_clock::now() };

	srand(time(0));//random seed
	
	CurrentRoom Room{};
	Player player{};

	EquippableItem GoldenHelmet{ "Golden helmet", 0, 15 };
	EquippableItem WoodenHelmet{ "Wooden helmet", 0, 5 };
	GoldenHelmet.SetReq(1, 1);
	WoodenHelmet.SetReq(0, 1);
	GoldenHelmet.bodyPart = "Head";
	WoodenHelmet.bodyPart = "Head";
	player.EQInv.push_back(GoldenHelmet);
	player.EQInv.push_back(WoodenHelmet);

	//Changes room cell on pos x,y with given char
	Room.CreateRoom();
	Room.ChangeRoomCell(player.x, player.y, player.PlayerChar);
	Room.PrintRoom();

	short action{};
	while (true) {
		//if it's time to update we can move and do stuff
		if (TimeUpdate(t_start)) {
			action = player.Move(Room.rows, Room.columns);
			if (Room.EnemiesInRoom.size() == 0) {//restart room if there arwe no enemies
				action = 9;
			}
			switch (action){
			case 1:// move or battle
				if (Room.GetCell(player.x, player.y) == 'E') {
					system("cls");
					short monster_index = Room.SearchEnemy(player);
					if (Battle(player, Room.EnemiesInRoom[monster_index])) {
						Room.EnemiesInRoom.erase(Room.EnemiesInRoom.begin() + monster_index);
					}
					player.LevelUp();
				}
				system("cls");
				std::cout << "Floor - " << Room.roomDeep << '\n';
				t_start = std::chrono::system_clock::now();
				if (Room.EnemiesInRoom.size() == 0) {
					action = 9;//restart room if there arwe no enemies
					break;
				}
				Room.ChangeRoomCell(player.x, player.y, player.PlayerChar);
				Room.ChangeRoomCell(player.saved_x, player.saved_y, ' ');
				Room.PrintRoom();
				break;
			case 9://create new room
				LoadingScreen();
				player.x = 1;
				player.y = 1;
				Room.CreateRoom();
				system("cls");
				Room.ChangeRoomCell(player.x, player.y, player.PlayerChar);
				Room.PrintRoom();
				break;
			case 3://show player stats
				player.PInfo();
				break;
			case 2:
				player.EQInvManager(); //Inventory using mech
				break;
			case -1://exit
				std::cout << "\nThank's for playing! Your progress is saved!\n";
				return 0;
			default:
				break;
			}
		}
	}
}