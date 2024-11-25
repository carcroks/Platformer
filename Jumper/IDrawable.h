#pragma once
#include "raylib.h"

class IDrawable
{
public:
	virtual void Draw() = 0;

	virtual bool checkCollision(Rectangle box) = 0;

	virtual Vector2 GetCollision(Rectangle hitbox) = 0;

	virtual bool OnGround(Vector2 loc1, Vector2 loc2) = 0;
};

