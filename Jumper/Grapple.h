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

	Vector2 direction;

	//create box
	Rectangle hitbox;

	Grapple(float x, float y, Vector2 direction);

	void Update();

	Vector2 CHeckCollision();
};

