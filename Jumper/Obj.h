#pragma once


class Obj
{
	public:
		int x;
		int y;
		const int unit = 10;

		explicit Obj(int xpos, int ypos);

		virtual void Draw();
};

