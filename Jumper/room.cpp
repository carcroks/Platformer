#include "room.h"

#include <iostream>
using namespace std;

room::room() {
}

void room::Draw() {

	for (int i = 0; i < objects.size(); i++) {
		objects.at(i)->Draw();
	}
}

void room::Add(IDrawable* o) {
	objects.push_back(o);
}



//A fusionner
bool room::CheckCollision(Rectangle hitbox) {
	for (int i = 0; i < objects.size(); i++) {
		if (objects.at(i)->checkCollision(hitbox))
			return true;
	}
	return false;
}


//R�cup�rer le r�sultat de celui qui � l'aire la plus grande (sinon bogue)
Vector2 room::GetCollision(Rectangle hitbox) {
	Vector2 res;
	for (int i = 0; i < objects.size(); i++) {
		if (objects.at(i)->checkCollision(hitbox))
			res = objects.at(i)->GetCollision(hitbox);
	}
	return res;
}

bool room::OnGround(Vector2 loc1, Vector2 loc2) {
	for (int i = 0; i < objects.size(); i++) {
		if (objects.at(i)->OnGround(loc1, loc2))
			return true;
	}
	return false;
}
