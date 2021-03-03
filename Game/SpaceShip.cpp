#include "SpaceShip.h"


SpaceShip::SpaceShip(SpaceShip_m ship_m)	//����ɴ�
{
	
	shape = ship_m.shape;
	Engine_power = ship_m.Engine_power;
	Health_Point = ship_m.Health_Point;
	mass = ship_m.mass;
	gun = new Gun(ShipGun_Modle[ship_m.Gun_type]);

}

SpaceShip::~SpaceShip() {}


void SpaceShip::Move_Forward()			//�ɴ�ǰ��
{
	acceleration = basic * Vect2(0, 1) * Engine_power;
}

void SpaceShip::Move_Backward()			//�ɴ�����
{
	acceleration = basic * Vect2(0, -1) * Engine_power;
}

void SpaceShip::Left_Rotate()			//�ɴ���ת
{
	rotate_speed = 200;
}

void SpaceShip::Right_Rotate()			//�ɴ���ת
{
	rotate_speed = -200;
}

void SpaceShip::Stop_Rotate()
{
	rotate_speed = 0;
}

void SpaceShip::Stop_Accelerate()		//ֹͣ����
{
	acceleration = Vect2(0, 0);
}

void SpaceShip::Brake()					//ɲ��
{
	velocity = velocity * 0.96f;
}


void SpaceShip::Shoot()					//����
{
	gun->shoot();
}

void SpaceShip::Set_gun_orientation(const Matrix2 &m)	//������������
{
	gun->basic = m;
}

void SpaceShip::InitSpaceShip(const Vect2 &pos)					//��ʼ��
{
	acceleration = Vect2(0, 1);
	position = pos;
}
void SpaceShip::Update(float dt)						//����
{
	
	
	//************************���ݸ���********************

	velocity = velocity* 0.99f;
	physical_Move(dt);			//�ɴ����ƶ�
	physical_Rotate(dt);		//�ɴ�����ת

	//***********************ǹ**************************
	
	gun->position = position;	//��������λ��
	gun->Update(dt);			//��������
}


void SpaceShip::Draw()							//��Ⱦ
{

	for (unsigned int i = 0; i < shape.size(); i++)
	{
		Vect2 start = position + basic * shape[i];
		Vect2 end = position + basic * shape[(i + 1) % shape.size()];
		Draw_line(start, end);
	}

	gun->Draw();		//������Ⱦ
	
}


void SpaceShip::DrawInCamera(const Camera &cam)	//�����Ⱦ
{
	Draw_Modle(shape, position - cam.position, basic);
	gun->DrawInCamera(cam);
}