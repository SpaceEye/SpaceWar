#pragma once
#include "tool.h"
#define BUTTON_UP		0
#define BUTTON_SELECTED	1
#define BUTTON_DOWN		2

//飞船船体模型和属性结构体
struct SpaceShip_m
{
public:
	std::vector<Vect2> shape;
	float Engine_power;
	float Health_Point;
	float mass;
	int Gun_type;
};

//飞船炮塔模型和属性结构体
struct ShipGun_m
{
public:
	std::vector<Vect2> shape;
};

//炮塔子弹模型和属性结构体
struct ShipBullet_m
{
public:
	std::vector<Vect2> shape;
	float power;
};

//敌人模型和属性结构体
struct Enemy_m
{
public:
	std::vector<Vect2> shape;
	float Engine_power;
	float Health_Point;
	float mass;
};

//UI界面模型
struct UI_m
{
public:
	std::vector<Vect2> shape;
};


extern std::vector<SpaceShip_m> SpaceShip_Modle;
extern std::vector<ShipGun_m> ShipGun_Modle;
extern std::vector<ShipBullet_m> ShipBullet_Modle;
extern std::vector<Enemy_m> Enemy_Modle;
extern std::vector<UI_m> UI_Modle;

extern void Modle_Load();