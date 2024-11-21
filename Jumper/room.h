#pragma once

#include <vector>
#include "raylib.h"
#include "IDrawable.h"

using namespace std;


class room
{
public:
	vector<IDrawable*> objects;

	room();

	void Draw();

	void Add(IDrawable* o);

	bool CheckGrappleCollision(Rectangle hitbox);

	Vector2 GetCollision(Rectangle hitbox);

};

