#include "Bullet.h"

Bullet::Bullet(ShipBullet_m bullet_m)
{
	shape = bullet_m.shape;

}

Bullet::~Bullet()
{

}

void Bullet::InitBullet(const Vect2 &pos, const float &pow, const float &speed, const Matrix2 &bas)
{
	position = pos;
	power = pow;
	basic = bas;
	velocity = basic * Vect2(0, 1) * speed;
}

void Bullet::Update(float dt)
{
	physical_Move(dt);
}

void Bullet::Draw()
{
	for (unsigned int i = 0; i < shape.size(); i++)
	{
		Vect2 start = position + basic*shape[i];
		Vect2 end = position + basic*shape[(i + 1) % shape.size()];
		Draw_line(start, end);
	}
}

void Bullet::DrawInCamera(const Camera &cam)	//Ïà»úäÖÈ¾
{
	Draw_Modle(shape, position - cam.position, basic);
}