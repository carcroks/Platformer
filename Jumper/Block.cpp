#include "Block.h"


Block::Block(int posx, int posy){
	//initiate coordinates
	x = posx;
	y = posy;

	//create box
	Rectangle test = Rectangle{100,100,100,100};

	//load sprite
	Image sprite = LoadImage("Assets/block.png");
	ImageResize(&sprite, 50, 50);
	texture = LoadTextureFromImage(sprite);
	UnloadImage(sprite);
}

void Block::Draw() {
	DrawTexture(texture, unit * x, unit * y, WHITE);
}
