#include "Wall.h"


Wall::Wall()
{
	shape.push_back(Vect2(-5000, 5000));
	shape.push_back(Vect2(5000, 5000));
	shape.push_back(Vect2(5000, -5000));
	shape.push_back(Vect2(-5000, -5000));

	//ÑÌ»¨
	/*shape.push_back(Vect2(0, -20)*4 + Vect2(700, 300));
	shape.push_back(Vect2(10, -30)*4 + Vect2(700, 300));
	shape.push_back(Vect2(20, -30)*4 + Vect2(700, 300));
	shape.push_back(Vect2(30, -20)*4 + Vect2(700, 300));
	shape.push_back(Vect2(30, -5)*4 + Vect2(700, 300));
	shape.push_back(Vect2(20, 10)*4 + Vect2(700, 300));
	shape.push_back(Vect2(0, 25)*4 + Vect2(700, 300));
	shape.push_back(Vect2(-20, 10)*4 + Vect2(700, 300));
	shape.push_back(Vect2(-30, -5)*4 + Vect2(700, 300));
	shape.push_back(Vect2(-30, -20)*4 + Vect2(700, 300));
	shape.push_back(Vect2(-20, -30)*4 + Vect2(700, 300));
	shape.push_back(Vect2(-10, -30)*4 + Vect2(700, 300));*/

	
	
	

}

Wall::~Wall()
{

}

int Wall::size()
{
	return shape.size();
}

Vect2 Wall::get(int i)
{
	return shape[i];
}

void Wall::Update(float dt)
{

}

void Wall::Draw()
{
	for (unsigned int i = 0; i < shape.size(); i++)
	{
		Vect2 start = shape[i];
		Vect2 end = shape[(i + 1) % shape.size()];
		Draw_line(start, end);
	}
}

void Wall::DrawInCamera(const Camera &cam)	//Ïà»úäÖÈ¾
{
	Draw_Modle(shape, position - cam.position, basic);
}

