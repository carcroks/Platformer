#pragma once
#include "raylib.h"
#include "Obj.h"


class Block : public Obj
{
public:
	Texture2D texture;

	explicit Block(int posx, int posy);

	void Draw() override;

};

