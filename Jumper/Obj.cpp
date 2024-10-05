#include "Obj.h"

#include <iostream>
using namespace std;

Obj::Obj(int xpos, int ypos) {
	x = xpos;
	y = ypos;
}

void Obj::Draw(){
	std::cout << "test";
}