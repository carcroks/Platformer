#pragma once



#include <vector>
#include "IDrawable.h"

using namespace std;


class room
{
public:
	vector<IDrawable*> objects;

	room();

	void Draw();

	void Add(IDrawable* o);

};

