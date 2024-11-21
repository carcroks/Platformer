#include "Character.h"

Character::Character(int xpos, int ypos) {
	x = xpos;
	y = ypos;
	state = NORMAL;
	myRoom = room;
}

void Character::Update() {
	if (state != PULLING) {
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

	if (myGrapple == nullptr)
		myGrapple.Update();

	x += (int)xspeed;
	y += (int)yspeed;

	if (IsKeyDown(KEY_E))
	{
		startGrapple(GetMousePosition());
	}
	if (IsKeyDown(KEY_S) && state == PULLING)
	{
		myGrapple = nullptr;

	}

	DrawRectangle(x, y, charWidth, charHeight, Color{ 127, 106, 79, 255 });
}

void Character::startGrapple(Vector2 mousePos) {
	state = GRAPPLING;
	Vector2 direction = getDirFromLocation(grappleSpeed, mousePos);
	myGrapple = &Grapple(x, y, direction, myRoom, this);
}

void Character::startPulling(Vector2 ancrage) {
	state = PULLING;
	Vector2 direction = getDirFromLocation(pullingSpeed, ancrage);
	xspeed = direction.x;
	yspeed = direction.y;
}



Vector2 Character::getDirFromLocation(int speed, Vector2 Pos) {
	float ratio = sqrt(pow((x - mousePos.x), 2) + pow((y - mousePos.y), 2)) / speed;
	float xdir = (x - mousePos.x) / ratio;
	float ydir = (y - mousePos.y) / ratio;
	return Vector2{ xdir, ydir };
}
