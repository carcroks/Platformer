#include "Character.h"

#include <iostream>
using namespace std;

Character::Character(int xpos, int ypos, room r) {
	x = xpos;
	y = ypos;
	state = NORMAL;
	myRoom = r;
	hitbox = Rectangle{ (float)x - charWidth / 2, (float)y - charHeight / 2};
}

void Character::Update() {
	if (state != PULLING && OnGround()) {
		if (IsKeyDown(KEY_A))
		{
			xspeed -= 5;
		}
		if (IsKeyDown(KEY_D))
		{
			xspeed += 5;
		}
		xspeed *= GroundFriction;
	}

	else if (state == PULLING) {
		if ((xspeed > 0 && x > ancrage.x) || (xspeed < 0 && x < ancrage.x)) {
			xspeed = 0;
			yspeed = 0;
		}
	}

	if (CheckCollision()) {
		xspeed = 0;
		yspeed = 0;
	}

	if (state == GRAPPLING)
		UpdateHook();

	x += (int)xspeed;
	y += (int)yspeed;

	if (IsKeyDown(KEY_E))
	{
		startGrapple(GetMousePosition());
	}
	if (IsKeyDown(KEY_S) && state == PULLING)
	{
		state = NORMAL;
	}

	DrawRectangle(x - charWidth/2, y - charHeight / 2, charWidth, charHeight, Color{ 127, 106, 79, 255 });
}

void Character::startGrapple(Vector2 mousePos) {
	state = GRAPPLING;
	Vector2 direction = getDirFromLocation(grappleSpeed, mousePos);
	hookxpos = x;
	hookypos = y;
	hookDirection = direction;
	HookHitbox = Rectangle{ (float)x - HookHitboxSize / 2, (float)y - HookHitboxSize / 2, (float)HookHitboxSize, (float)HookHitboxSize };
	//ancrage = { 0, 0 };
	myHookState = FLYING;

}

void Character::startPulling() {
	state = PULLING;
	Vector2 direction = getDirFromLocation(pullingSpeed, ancrage);
	xspeed = direction.x;
	yspeed = direction.y;
}

Vector2 Character::getDirFromLocation(int speed, Vector2 Pos) {
	float ratio = speed / sqrt(pow((x - Pos.x), 2) + pow((y - Pos.y), 2));
	float xdir = (Pos.x - x)  *  ratio;
	float ydir = (Pos.y - y)  *  ratio;
	return Vector2{ xdir, ydir };
}

//à régler
bool Character::OnGround() {
	return y == 0;
}

bool Character::CheckCollision() {
	Rectangle futureHitbox = { x + xspeed - charWidth / 2, y + yspeed - charHeight / 2 };
	return (myRoom.CheckCollision(futureHitbox));
}

//hook treatment

void Character::UpdateHook() {
	if (myHookState == FLYING) {
		hookxpos = hookxpos + hookDirection.x;
		hookypos = hookypos + hookDirection.y;

		if (CheckHookCollision()) {
			myHookState = ATTACHED;
			ancrage = GetHookCollision();
			hookxpos = ancrage.x;
			hookypos = ancrage.y;
			startPulling();
		}

		HookHitbox.x = hookxpos - HookHitboxSize / 2;
		HookHitbox.y = hookypos - HookHitboxSize / 2;
	}

	DrawLine((int)hookxpos, (int)hookypos, x, y, Color{ 255, 0, 0, 255 });

	if (myHookState = FLYING)
		DrawRectangleRec(HookHitbox, Color{ 255, 0, 0, 255 });
	else
		DrawRectangleRec(HookHitbox, Color{ 0, 0, 255, 255 });

}

bool Character::CheckHookCollision() {
	return myRoom.CheckCollision(HookHitbox);
}

Vector2 Character::GetHookCollision() {
	return myRoom.GetCollision(HookHitbox);
}
