#pragma once
#include "Enemy.h"

Enemy::Enemy(Enemy_m enemy)
{
	shape = enemy.shape;
	InitEnemy();
}

Enemy::~Enemy()
{

}
void Enemy::InitEnemy()
{

}

//void Enemy::Set_Pos(Vect2 pos)
//{
//	position = pos;
//}
//
//void Enemy::Set_Vel(Vect2 vel)
//{
//	velocity = vel;
//}

void Enemy::Update(float dt)
{
	physical_Move(dt);
}

void Enemy::Draw()
{
	for (unsigned int i = 0; i < shape.size(); i++)
	{
		Vect2 start = position + basic * shape[i];
		Vect2 end = position + basic * shape[(i + 1) % shape.size()];
		Draw_line(start, end);
	}
}

void Enemy::DrawInCamera(const Camera &cam)	//Ïà»úäÖÈ¾
{
	Draw_Modle(shape, position - cam.position, basic);
}