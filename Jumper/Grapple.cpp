#include "Grapple.h"
#include "room.h"

Grapple::Grapple(float x, float y, Vector2 dir, room r) {
	xpos = x;
	ypos = y;
	myRoom = r;
	direction = dir;
	hitbox = Rectangle{ x, y , 20, 20 };
	state = FLYING;
}

void Grapple::Update() {
	if (state == FLYING) {
		xpos = xpos + direction.x;
		ypos = ypos + direction.y;
	}
	
}

bool Grapple::CheckCollision() {
	return myRoom.CheckCollision(hitbox);
}

Vector2 Grapple::GetCollision() {
	return myRoom.GetCollision(hitbox);
}