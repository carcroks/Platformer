#include "Grapple.h"
#include "room.h"

Grapple::Grapple(float x, float y, Vector2 dir, room r, Character c) {
	xpos = x;
	ypos = y;
	myRoom = r;
	direction = dir;
	hitbox = Rectangle{ x - 10, y - 10, 20, 20 };
	state = FLYING;
	myCharacter = c;
}

void Grapple::Update() {
	if (state == FLYING) {
		xpos = xpos + direction.x;
		ypos = ypos + direction.y;
		hitbox.SetX(xpos - 10);
		hitbox.setY(ypos - 10);
	}
	DrawLine((int)x, (int)y, c.x, c.y, Color{ 255, 0, 0, 255 });
	DrawRectangleRec(hitbox, Color{ 255, 0, 0, 255 })
	
}

bool Grapple::CheckCollision() {
	return myRoom.CheckCollision(hitbox);
}

Vector2 Grapple::GetCollision() {
	return myRoom.GetCollision(hitbox);
}