#include "Headers\Hub.h"


int Hub::Home(Player& player, bool rest)
{
	system("cls");
	std::cout << "You are in your house. You can 1 - sleep, 2 - upgrade your house\n";
	char choice{};
	std::cin >> choice;
	switch (choice) {
		case '1':
		{
			if (rest) {
				int restoreHp{ 0 };
				if (HomeLvl == 4) {
					restoreHp = player.GetMaxHp();
				}
				else {
					restoreHp = player.GetMaxHp() / (4 - HomeLvl);
				}
				std::cout << "You sleep well...And restored " << restoreHp << " hp!\n";
				return restoreHp;
				
			}
			else {
				std::cout << "You can't rest now, go fight!\n";
				return 0;
			}
			break;
		}
		case '2':
			Upgrade('h', player.GetMoney());
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
			int tempHp = this->Home(player, player.canSleep);
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

void Hub::Upgrade(char b_type, double& p_money)
{
	switch (b_type) {
		case 'h':
			if (HomeLvl < 4 && p_money >= H_cost) {
				this->HomeLvl++;
				p_money -= H_cost;
				this->H_cost += 100;
				std::cout << "Home upgraded to " << this->HomeLvl << " lvl\n";
				std::cout << "Now you can restore more HP while sleep.\n";
			}
			else if (p_money < H_cost) {
				std::cout << "Not enought money!\n";
			}
			else {
				std::cout << "Your house on maxed level!\n";
			}
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