#pragma once

#include <iostream>

class Hub {

public:

	short Home(int maxHp = 0, double currentMoney = 0);

	void Shop();

	void Blacksmith();

	void HubManager();

private:

	short HomeLvl{1}, ShopLvl{1}, BlacksmithLvl{1};

	void UpgradeHome();
};