#pragma once



#include <vector>
#include "Obj.h"

using namespace std;


class room
{
public:
	vector<Obj> objects;

	room();

	void Draw();

	void Add(Obj o);
};

