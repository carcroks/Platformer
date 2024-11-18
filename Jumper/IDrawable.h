#pragma once
class IDrawable
{
public:
	virtual void Draw() = 0;

	virtual bool checkCollision(Rectangle box);

	virtual Vector2 GetCollision(Rectangle hitbox);
};

