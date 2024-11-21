#pragma once
#include "raylib.h"

enum GrappleState {
	FLYING,
	ATTACHED
};

class Grapple
{
	float xpos;
	float ypos;

	enum GrappleState state;

	room myRoom;

	Character myCharacter;

	Vector2 direction;

	//create box
	Rectangle hitbox;

	Grapple(float x, float y, Vector2 direction, room r, Character c);

	bool CheckCollision();

	Vector2 GetCollision();

public:
	void Update();
};

