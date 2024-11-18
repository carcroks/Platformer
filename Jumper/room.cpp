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
bool room::CheckGrappleCollision(Rectangle hitbox) {
	for (int i = 0; i < objects.size(); i++) {
		if (objects.at(i)->checkCollision(hitbox))
			return true;
	}
	return false;
}


//Récupérer le résultat de celui qui à l'aire la plus grande (sinon bogue)
Vector2 room::GetCollision(Rectangle hitbox) {
	Vector2 res;
	for (int i = 0; i < objects.size(); i++) {
		if (objects.at(i)->checkCollision(hitbox))
			res = objects.at(i)->GetCollision(hitbox);
	}
	return res;
}
