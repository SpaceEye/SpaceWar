#pragma once
#include "GameObject.h"
#include "Camera.h"
#include "Modle.h"
#include "Gun.h"

class SpaceShip : public GameObject_phy
{
private:

public:


	float Engine_power;		//���涯��
	float Health_Point;		//����ֵ
	float mass;				//����
	



	Gun *gun;				//����
	
	SpaceShip(SpaceShip_m ship);	//�ɴ����캯��
	~SpaceShip();
	void InitSpaceShip(const Vect2 &pos);	//��ʼ���ɴ�

	void Move_Forward();		//ǰ��
	void Move_Backward();		//����
	void Left_Rotate();			//��ת
	void Right_Rotate();		//��ת
	void Stop_Accelerate();		//ֹͣ����
	void Stop_Rotate();			//ֹͣ��ת
	void Brake();				//ɲ��
	void Shoot();				//����



	void Set_gun_orientation(const Matrix2 &m);	//����ǹ�ĳ���



	void Update(float dt) override;		//����
	void Draw() override;				//��Ⱦ
	void DrawInCamera(const Camera &cam) override;	//���������Ⱦ
};
