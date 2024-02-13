#include "Headers\Hub.h"


int Hub::Home(int maxHp,double currentMoney, bool rest)
{
	system("cls");
	std::cout << "You are in your house. You can 1 - sleep, 2 - upgrade your house\n";
	char choice{};
	std::cin >> choice;
	switch (choice) {
		case '1':
		{
			if (rest) {
				int restoreHp{ maxHp / 4 };
				std::cout << "You sleep well...And restored " << restoreHp << " hp!\n";
				return restoreHp;
			}
			else {
				std::cout << "You can't rest now, go fight!\n";
				return 0;
			}
			
		}
		case '2':
			Upgrade('h');
			break;
		default:
			break;
	}
	return 0;
}

void Hub::Shop()
{

}

void Hub::Blacksmith()
{

}

bool Hub::HubManager(Player& player)
{
	std::cout << "You are in Hub. Choose were to go (1 - home, 2 - shop, 3 - blacksmith, 4 - go to dungeon\n";
	char choice{};
	std::cin >> choice;

	switch (choice)
	{
		case '1':
		{
			player.canSleep = CanSleep(player.totalEnemyKills);
			int tempHp = this->Home(player.GetMaxHp(), player.GetMoney(), player.canSleep);
			player.AddHp(tempHp);
			if (tempHp != 0) {
				killsOnSleep = player.totalEnemyKills;
				player.canSleep = false;
			}
			break;
		}
			
		case '2':
			this->Shop();
			break;
		case '3':
			this->Blacksmith();
			break;
		case '4':
			return true;
		default:
			break;
	}
	HubManager(player);
}

void Hub::Upgrade(char b_type)
{
	switch (b_type) {
		case 'h':
			this->HomeLvl++;
			this->H_cost += 100;
			std::cout << "Home upgraded to " << this->HomeLvl << " lvl\n";
			break;
		case 's':
			this->ShopLvl++;
			this->S_cost += 100;
			std::cout << "Shop upgraded to " << this->ShopLvl << " lvl\n";
			break;
		case 'b':
			this->BlacksmithLvl++;
			this->B_cost += 100;
			std::cout << "Shop upgraded to " << this->ShopLvl << " lvl\n";
			break;
	}

}

bool Hub::CanSleep(int nowKills) {
	
	if (nowKills - killsOnSleep >= 2) {
		return true;
	}
	else {
		return false;
	}
}