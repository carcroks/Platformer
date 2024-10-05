#pragma once


#include "raylib.h"


class Character
{

public:
	int x;
	int y;


	const int charWidth = 30;
	const int charHeight = 50;

	const float GroundFriction = 0.8;
	float xspeed = 0;

	Character(int xpos, int ypos);

	void Update();
};

