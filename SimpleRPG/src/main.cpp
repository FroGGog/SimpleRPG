#include <chrono>
#include <iostream>

#include "Headers/Room.h"
#include "Headers/Player.h"
#include "Headers/Monster.h"

const double FPS{ 0.05 };

//Update screen time calculation
bool TimeUpdate(std::chrono::system_clock::time_point t_start) {

	std::chrono::duration<float> UPDTime{ std::chrono::system_clock::now() - t_start };

	return UPDTime.count() > ::FPS;

}


void Battle(Player& player, Monster &enemy) {
	char choice{};
	enemy.printInfo();
	while (!player.Death() && !enemy.Death()) {
		choice = player.BattleOptions();
		system("cls");
		if (choice == '1') {
			player.Attack(enemy);
		}
		player.TakeDamage(enemy.GetName(), enemy.GetDamage());
	}
	if (player.Death()) {
		std::cout << "\nX_X You dead X_X\n";
	}
	else if (enemy.Death()) {
		std::cout << "\nYou won! You got " << enemy.GetExp() << " xp\n";
		std::cout << "Press any button to continue...\n";
		player.AddExp(enemy.GetExp());
		std::cin.ignore();
		std::cin.get();
	}
	

}


int main() {

	auto t_start{ std::chrono::system_clock::now() };
	
	CurrentRoom Room{10, 25};
	Player player{};
	Monster goblin{"Goblin", 25, 100, 1};
	//Changes room cell on pos x,y with given char
	Room.ChangeRoomCell(player.x, player.y, player.PlayerChar);
	Room.ChangeRoomCell(5, 5, 'M');
	Room.PrintRoom();
	while (true) {
		//if it's time to update we can move and do stuff
		if (TimeUpdate(t_start)) {
			if (player.Move()) {
				if (Room.StartBattle(player.x, player.y)) {
					system("cls");
					Battle(player, goblin);
					player.LevelUp();
				}				
				system("cls");
				t_start = std::chrono::system_clock::now();
				Room.ChangeRoomCell(player.x, player.y, player.PlayerChar);
				Room.ChangeRoomCell(player.saved_x, player.saved_y, ' ');
				Room.PrintRoom();
			}
		}
	}
	




}