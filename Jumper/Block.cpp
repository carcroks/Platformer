#include "Block.h"
#include <stdlib.h>


Block::Block(int posx, int posy){
	//initiate coordinates
	x = posx;
	y = posy;

	//create box
	myBox = Rectangle{x,y,width,width};

	//load sprite
	Image sprite = LoadImage("Assets/block.png");
	ImageResize(&sprite, 50, 50);
	texture = LoadTextureFromImage(sprite);
	UnloadImage(sprite);
}

void Block::Draw() {
	DrawTexture(texture, width * x, width * y, WHITE);
}

bool Block::checkCollision(Rectangle box) {
	return (CheckCollisionRecs(box, myBox));
}

Vector2 Block::GetCollision(Rectangle hitbox) {
	Vector2 objCenter{ myBox.GetX() + myBox.GetWidth() / 2 , myBox.GetY() + myBox.GetHeight() / 2};

	Vector2 GrapCenter{ hitbox.GetX() + hitbox.GetWidth() / 2 , hitbox.GetY() + hitbox.GetHeight() / 2 };

	Vector2 line = GrapCenter - objCenter;

	Vector2 lineCopy{ abs(line.x), abs(line.y) };

	Vector2 res;

	float factor;

	if (lineCopy.x > lineCopy.y)
		float factor = width / lineCopy.x;
	else
		float factor = width / lineCopy.y;

	res.SetX(objCenter.x - line.x * factor);
	res.SetY(objCenter.y - line.y * factor);

	return res;
}
