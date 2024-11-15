#include "room.h"

#include <iostream>
using namespace std;

room::room() {
}

void room::Draw() {
	/*for (auto& object : objects)
	{

		Block* b = dynamic_cast<Block*>(&object);
		if (b == nullptr)
			cout << "null" << endl;

		b->Draw();
	}*/

	/*for (int i = 0; i < objects.size(); i++)
	{
		Block* b = dynamic_cast<Block*>(objects.at(i));
		if (b)
			b->Draw();
		else
			cout << "test" << endl;
	}*/

	for (int i = 0; i < objects.size(); i++) {
		objects.at(i)->Draw();
	}
}

void room::Add(IDrawable* o) {
	objects.push_back(o);
}
