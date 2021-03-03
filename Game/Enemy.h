#pragma once
#include "GameObject.h"
#include "Modle.h"

class Enemy:public GameObject_phy
{
public:
	Enemy(Enemy_m enemy);
	~Enemy();

	float Engine_power;		//引擎动力
	float Health_Point;		//生命值
	float mass;				//质量

	void InitEnemy();
	

	void Update(float dt) override;
	void Draw() override;
	void DrawInCamera(const Camera &cam) override;

};