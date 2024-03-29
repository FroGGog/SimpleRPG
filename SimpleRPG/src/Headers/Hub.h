#pragma once

#include <iostream>
#include "Player.h"

class Hub {

public:

	int Home(Player& player, bool rest = true);

	void Shop();

	void Blacksmith();

	bool HubManager(Player& player);

	

private:

	short HomeLvl{1}, ShopLvl{1}, BlacksmithLvl{1};

	int H_cost{ 100 }, S_cost{ 100 }, B_cost{ 100 }, killsOnSleep{};

	void Upgrade(char b_type, double& p_money);
	bool CanSleep(int nowKills);
};