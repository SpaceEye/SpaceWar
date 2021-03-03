#include "Particle.h"


Particle::Particle():duration(0)
{
	InitParticle();
}

Particle::~Particle()
{

}

void Particle::InitParticle()
{
	shape.push_back(Vect2(0, 0));
	shape.push_back(Vect2(0, 1));
	
}


void Particle::Set_Shape(const std::vector<Vect2> &new_shape)
{
	shape = new_shape;
}


void Particle::Update(float dt)
{
	int R = (int)Random::random_in(0, 255);
	int G = (int)Random::random_in(0, 255);
	int B = (int)Random::random_in(0, 255);
	color = RGB(R, G, B);
	physical_Move(dt);
}

void Particle::Draw()
{
	setlinecolor(color);
	for (unsigned int i = 0; i < shape.size(); i++)
	{
		Vect2 start = position + shape[i] ;
		Vect2 end = position + shape[(i + 1) % shape.size()];
		Draw_line(start, end);
	}

}

void Particle::DrawInCamera(const Camera &cam)	//Ïà»úäÖÈ¾
{
	setlinecolor(color);
	Draw_Modle(shape, position - cam.position, basic);
}