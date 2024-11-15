#include "Grapple.h"

Grapple::Grapple(float x, float y, Vector2 dir) {
	xpos = x;
	ypos = y;
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
