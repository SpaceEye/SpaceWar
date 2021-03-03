#pragma once
#include "GameObject.h"
#include "Camera.h"
#include "Modle.h"
#include "Gun.h"

class SpaceShip : public GameObject_phy
{
private:

public:


	float Engine_power;		//引擎动力
	float Health_Point;		//生命值
	float mass;				//质量
	



	Gun *gun;				//炮塔
	
	SpaceShip(SpaceShip_m ship);	//飞船构造函数
	~SpaceShip();
	void InitSpaceShip(const Vect2 &pos);	//初始化飞船

	void Move_Forward();		//前进
	void Move_Backward();		//后退
	void Left_Rotate();			//左转
	void Right_Rotate();		//右转
	void Stop_Accelerate();		//停止加速
	void Stop_Rotate();			//停止旋转
	void Brake();				//刹车
	void Shoot();				//开火



	void Set_gun_orientation(const Matrix2 &m);	//设置枪的朝向



	void Update(float dt) override;		//更新
	void Draw() override;				//渲染
	void DrawInCamera(const Camera &cam) override;	//在相机中渲染
};
