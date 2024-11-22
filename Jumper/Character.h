#pragma once

#include <cmath>
#include "raylib.h"
#include "room.h"


enum CharacterState {
	GRAPPLING,
	NORMAL,
	PULLING
};

enum hookState {
	FLYING,
	ATTACHED
};

class Character
{

public:
	int x;
	int y;

	enum CharacterState state;

	room myRoom;

	Rectangle hitbox;

	const int charWidth = 30;
	const int charHeight = 50;

	const int grappleSpeed = 12;
	const int pullingSpeed = 8;

	const float GroundFriction = 0.8;
	float yspeed = 0;
	float xspeed = 0;

	Character(int xpos, int ypos, room myRoom);

	void Update();

	void startGrapple(Vector2 mousePos);

	void startPulling();

	Vector2 getDirFromLocation(int speed, Vector2 mousePos);

	bool OnGround();

	bool CheckCollision();



	//Grapple

	float hookxpos;
	float hookypos;

	enum hookState myHookState;

	Character* myCharacter;

	Vector2 hookDirection;

	Rectangle HookHitbox;

	const int HookHitboxSize = 20;

	bool CheckHookCollision();

	Vector2 GetHookCollision();

	void UpdateHook();
	
	Vector2 ancrage;
};

