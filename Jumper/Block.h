#pragma once
#include "raylib.h"
#include "IDrawable.h"



class Block : public IDrawable
{
public:
	Texture2D texture;

	int x;
	int y;
	const int width = 50;

	Rectangle myBox;

	explicit Block(int posx, int posy);

	void Draw() override;

	bool checkCollision(Rectangle box) override;

	Vector2 GetCollision(Rectangle hitbox) override;

};

