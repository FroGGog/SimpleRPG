#pragma once

class Player {

public:

	short x{}, y{};
	short saved_x{}, saved_y{};
	char PlayerChar{ 'P' };

	Player(short _x = 1, short _y = 1);

	bool Move();

};