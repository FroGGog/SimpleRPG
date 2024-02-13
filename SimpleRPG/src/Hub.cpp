#include "Headers\Hub.h"



short Hub::Home(int maxHp,double currentMoney)
{
	system("cls");
	std::cout << "You are in your house. You can 1 - sleep, 2 - upgrade your house\n";
	char choice{};
	switch (choice) {
		case '1':
		{
			int restoreHp{ maxHp / 4 };
			std::cout << "You sleep well...And restored " << restoreHp << " hp!";
			return restoreHp;
		}
		case '2':
			UpgradeHome();
			break;
		default:
			break;
	}
}

void Hub::Shop()
{

}

void Hub::Blacksmith()
{

}

void Hub::HubManager()
{
	system("cls");
	std::cout << "You are in Hub. Choose were to go (1 - home, 2 - shop, 3 - blacksmith, 4 - go to dungeon\n";
	char choice{};
	std::cin >> choice;

	switch (choice)
	{
		case '1':
			this->Home();
			break;
		case '2':
			this->Shop();
			break;
		case '3':
			this->Blacksmith();
			break;
		case '4':
			return;
		default:
			break;
	}
	HubManager();
}

void Hub::UpgradeHome()
{
	this->HomeLvl++;
	std::cout << "Home upgraded to " << this->HomeLvl << " lvl\n";

}
