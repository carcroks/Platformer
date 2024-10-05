#include "Character.h"

Character::Character(int xpos, int ypos) {
	x = xpos;
	y = ypos;
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

	xspeed *= GroundFriction;
	x += (int)xspeed;

	DrawRectangle(x, y, charWidth, charHeight, Color{ 127, 106, 79, 255 });
}
