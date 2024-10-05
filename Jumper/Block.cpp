#include "Block.h"

Block::Block(int posx, int posy) : Obj(posx, posy) {
	Image sprite = LoadImage("Assets/block.png");
	texture = LoadTextureFromImage(sprite);
	UnloadImage(sprite);
}

void Block::Draw() {
	DrawTexture(texture, unit * x, unit * y, WHITE);
}
