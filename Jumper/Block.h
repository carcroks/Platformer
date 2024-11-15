#pragma once
#include "raylib.h"
#include "IDrawable.h"



class Block : public IDrawable
{
public:
	Texture2D texture;

	int x;
	int y;
	const int unit = 10;

	explicit Block(int posx, int posy);

	void Draw() override;

};

