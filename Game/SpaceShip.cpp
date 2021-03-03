#include "SpaceShip.h"


SpaceShip::SpaceShip(SpaceShip_m ship_m)	//载入飞船
{
	
	shape = ship_m.shape;
	Engine_power = ship_m.Engine_power;
	Health_Point = ship_m.Health_Point;
	mass = ship_m.mass;
	gun = new Gun(ShipGun_Modle[ship_m.Gun_type]);

}

SpaceShip::~SpaceShip() {}


void SpaceShip::Move_Forward()			//飞船前进
{
	acceleration = basic * Vect2(0, 1) * Engine_power;
}

void SpaceShip::Move_Backward()			//飞船后退
{
	acceleration = basic * Vect2(0, -1) * Engine_power;
}

void SpaceShip::Left_Rotate()			//飞船左转
{
	rotate_speed = 200;
}

void SpaceShip::Right_Rotate()			//飞船右转
{
	rotate_speed = -200;
}

void SpaceShip::Stop_Rotate()
{
	rotate_speed = 0;
}

void SpaceShip::Stop_Accelerate()		//停止加速
{
	acceleration = Vect2(0, 0);
}

void SpaceShip::Brake()					//刹车
{
	velocity = velocity * 0.96f;
}


void SpaceShip::Shoot()					//开火
{
	gun->shoot();
}

void SpaceShip::Set_gun_orientation(const Matrix2 &m)	//设置炮塔朝向
{
	gun->basic = m;
}

void SpaceShip::InitSpaceShip(const Vect2 &pos)					//初始化
{
	acceleration = Vect2(0, 1);
	position = pos;
}
void SpaceShip::Update(float dt)						//更新
{
	
	
	//************************数据更新********************

	velocity = velocity* 0.99f;
	physical_Move(dt);			//飞船的移动
	physical_Rotate(dt);		//飞船的旋转

	//***********************枪**************************
	
	gun->position = position;	//链接炮塔位置
	gun->Update(dt);			//更新炮塔
}


void SpaceShip::Draw()							//渲染
{

	for (unsigned int i = 0; i < shape.size(); i++)
	{
		Vect2 start = position + basic * shape[i];
		Vect2 end = position + basic * shape[(i + 1) % shape.size()];
		Draw_line(start, end);
	}

	gun->Draw();		//炮塔渲染
	
}


void SpaceShip::DrawInCamera(const Camera &cam)	//相机渲染
{
	Draw_Modle(shape, position - cam.position, basic);
	gun->DrawInCamera(cam);
}