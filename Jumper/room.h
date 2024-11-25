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

	bool CheckCollision(Rectangle hitbox);

	Vector2 GetCollision(Rectangle hitbox);

	bool OnGround(Vector2 loc1, Vector2 loc2);

};

