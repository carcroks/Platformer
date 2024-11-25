#include "Block.h"
#include <stdlib.h>


Block::Block(int posx, int posy){
	//initiate coordinates
	x = posx;
	y = posy;

	//create box
	myBox = Rectangle{(float)x * width, (float)y * width, (float)width, (float)width};

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
	Vector2 objCenter{ myBox.x + myBox.width / 2 , myBox.y + myBox.height / 2};

	Vector2 GrapCenter{ hitbox.x + hitbox.width / 2 , hitbox.y + hitbox.height / 2 };

	Vector2 line = { GrapCenter.x - objCenter.x, GrapCenter.y - objCenter.y };

	Vector2 lineCopy{ abs((int)line.x), abs((int)line.y) };

	Vector2 res;

	float factor = 0;

	if (lineCopy.x > lineCopy.y)
		float factor = width / lineCopy.x;
	else
		float factor = width / lineCopy.y;

	res.x = (objCenter.x - line.x * factor);
	res.y = (objCenter.y - line.y * factor);

	return res;
}

bool Block::OnGround(Vector2 loc1, Vector2 loc2) {
	float xmin = (float)x * width;
	float xmax = xmin + width;
	float yBon = (float)y * width;
	return ((loc1.x >= xmin && loc1.x <= xmax && loc1.y == yBon) || (loc2.x >= xmin && loc2.x <= xmax && loc2.y == yBon));
}
