#include "room.h"

room::room() {
}

void room::Draw() {
	for (auto& object : objects)
	{
		object.Draw();
	}
}

void room::Add(Obj o) {
	objects.push_back(o);
}
