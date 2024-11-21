#pragma once

#include <cmath>
#include "raylib.h"
#include "Grapple.h"
#include "room.h"


enum CharacterState {
	GRAPPLING,
	NORMAL,
	PULLING
};

class Character
{

public:
	int x;
	int y;

	enum CharacterState state;

	room myRoom;

	Grapple* myGrapple;
	


	const int charWidth = 30;
	const int charHeight = 50;

	const int grappleSpeed = 5;
	const int pullingSpeed = 5;

	const float GroundFriction = 0.8;
	float yspeed = 0;
	float xspeed = 0;

	Character(int xpos, int ypos, room myRoom);

	void Update();

	void startGrapple(Vector2 mousePos);

	void startPulling();

	Vector2 getDirFromLocation(int speed, Vector2 mousePos);

};

