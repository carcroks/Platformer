#include "Character.h"

Character::Character(int xpos, int ypos) {
	x = xpos;
	y = ypos;
	state = NORMAL;
}

void Character::Update() {
	if (IsKeyDown(KEY_A))
	{
		xspeed -= 5;
	}
	if (IsKeyDown(KEY_D))
	{
		xspeed += 5;
	}
	if (IsKeyDown(KEY_E))
	{
		startGrapple(GetMousePosition());
	}

	xspeed *= GroundFriction;
	x += (int)xspeed;

	DrawRectangle(x, y, charWidth, charHeight, Color{ 127, 106, 79, 255 });
}

void Character::startGrapple(Vector2 mousePos) {
	state = GRAPPLING;
	Vector2 direction = getDirFromMousePos(10, mousePos);


}

Vector2 Character::getDirFromMousePos(int speed, Vector2 mousePos) {
	float ratio = sqrt(pow((x - mousePos.x), 2) + pow((y - mousePos.y), 2)) / speed;
	float xdir = (x - mousePos.x) / ratio;
	float ydir = (y - mousePos.y) / ratio;
	return Vector2{ xdir, ydir };
}
