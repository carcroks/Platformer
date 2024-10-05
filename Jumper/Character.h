#pragma once


#include "main.h"


class Character
{

public:
	int x;
	int y;


	const int charWidth = 30;
	const int charHeight = 50;

	const float GroundFriction = 0.8;
	int xspeed = 0;

	Character(int xpos, int ypos) {
		x = xpos;
		y = ypos;
	}

	void Update() {
		if (IsKeyDown(KEY_A))
		{
			xspeed -= 5;
		}
		if (IsKeyDown(KEY_D))
		{
			xspeed += 5;
		}

		xspeed *= GroundFriction;
		x += xspeed;

		DrawRectangle(x, y, charWidth, charHeight, Color{ 127, 106, 79, 255 });
	}
};

