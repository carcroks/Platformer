#pragma once

#include <cmath>
#include "raylib.h"
#include "Grapple.h"


enum CharacterState {
	GRAPPLING,
	NORMAL
};

class Character
{

public:
	int x;
	int y;

	enum CharacterState state;
	


	const int charWidth = 30;
	const int charHeight = 50;

	const float GroundFriction = 0.8;
	float xspeed = 0;

	Character(int xpos, int ypos);

	void Update();

	void startGrapple(Vector2 mousePos);

	Vector2 getDirFromMousePos(int speed, Vector2 mousePos);

};

