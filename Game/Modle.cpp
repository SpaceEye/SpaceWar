
#include "Modle.h"



std::vector<SpaceShip_m> SpaceShip_Modle;		//飞船模型集合
std::vector<ShipGun_m> ShipGun_Modle;			//炮塔模型集合
std::vector<ShipBullet_m> ShipBullet_Modle;		//子弹模型集合
std::vector<Enemy_m> Enemy_Modle;				//敌人模型集合

std::vector<UI_m> UI_Modle;


SpaceShip_m basic_ship;

ShipGun_m basic_gun;

ShipBullet_m basic_bullet;

Enemy_m basic_enemy;
Enemy_m next_enemy;
Enemy_m last_enemy;

UI_m Button_UP, Button_SELECTED, Button_DOWN;

void Modle_Load()
{
	//basic_ship shape
	{
		basic_ship.shape.push_back(Vect2(0, 50));
		basic_ship.shape.push_back(Vect2(10, 30));
		basic_ship.shape.push_back(Vect2(5, 20));
		basic_ship.shape.push_back(Vect2(10, 10));
		basic_ship.shape.push_back(Vect2(15, 0));
		basic_ship.shape.push_back(Vect2(20, 10));
		basic_ship.shape.push_back(Vect2(30, 0));
		basic_ship.shape.push_back(Vect2(20, -30));
		basic_ship.shape.push_back(Vect2(10, -10));
		basic_ship.shape.push_back(Vect2(5, -20));
		basic_ship.shape.push_back(Vect2(4, -25));
		basic_ship.shape.push_back(Vect2(-4, -25));
		basic_ship.shape.push_back(Vect2(-5, -20));
		basic_ship.shape.push_back(Vect2(-10, -10));
		basic_ship.shape.push_back(Vect2(-20, -30));
		basic_ship.shape.push_back(Vect2(-30, 0));
		basic_ship.shape.push_back(Vect2(-20, 10));
		basic_ship.shape.push_back(Vect2(-15, 0));
		basic_ship.shape.push_back(Vect2(-10, 10));
		basic_ship.shape.push_back(Vect2(-5, 20));
		basic_ship.shape.push_back(Vect2(-10, 30));
	}
	basic_ship.Engine_power = 500.0f;
	basic_ship.Health_Point = 100.0f;
	basic_ship.mass = 100.0f;
	basic_ship.Gun_type = 0;

	SpaceShip_Modle.push_back(basic_ship);



	/***************************飞船模型************************************/

	{
		basic_gun.shape.push_back(Vect2(2.5, 30));
		basic_gun.shape.push_back(Vect2(2.5, 10));
		basic_gun.shape.push_back(Vect2(5, 10));
		basic_gun.shape.push_back(Vect2(5, -7.5));
		basic_gun.shape.push_back(Vect2(-5, -7.5));
		basic_gun.shape.push_back(Vect2(-5, 10));
		basic_gun.shape.push_back(Vect2(-2.5, 10));
		basic_gun.shape.push_back(Vect2(-2.5, 30));
	}
	
	ShipGun_Modle.push_back(basic_gun);

	/***************************飞船子弹模型************************************/
	{
		basic_bullet.shape.push_back(Vect2(-2, -2));
		basic_bullet.shape.push_back(Vect2(-2, 5));
		basic_bullet.shape.push_back(Vect2(0, 8));
		basic_bullet.shape.push_back(Vect2(2, 5));
		basic_bullet.shape.push_back(Vect2(2, -2));
		basic_bullet.power = 10;
	}
	ShipBullet_Modle.push_back(basic_bullet);

	/***************************敌人模型************************************/
	{
		basic_enemy.shape.push_back(Vect2(0, -10));
		basic_enemy.shape.push_back(Vect2(10, 0));
		basic_enemy.shape.push_back(Vect2(0, 80));
		basic_enemy.shape.push_back(Vect2(-10, 0));
	}
	Enemy_Modle.push_back(basic_enemy);

	{
		next_enemy.shape.push_back(Vect2(-10, -10));
		next_enemy.shape.push_back(Vect2(10, -10));
		next_enemy.shape.push_back(Vect2(20, 0));
		next_enemy.shape.push_back(Vect2(10, 0));
		next_enemy.shape.push_back(Vect2(0, 10));
		next_enemy.shape.push_back(Vect2(-10, 0));
		next_enemy.shape.push_back(Vect2(-20, 0));
	}
	Enemy_Modle.push_back(next_enemy);

	/***************************UI模型************************************/
	{
		Button_UP.shape.push_back(Vect2(20, 5));
		Button_UP.shape.push_back(Vect2(20, -5));
		Button_UP.shape.push_back(Vect2(-20, -5));
		Button_UP.shape.push_back(Vect2(-19, -6));
		Button_UP.shape.push_back(Vect2(21, -6));
		Button_UP.shape.push_back(Vect2(21, 4));
		Button_UP.shape.push_back(Vect2(20, 5));
		Button_UP.shape.push_back(Vect2(-20, 5));
		Button_UP.shape.push_back(Vect2(-20, -5));

		Button_SELECTED.shape.push_back(Vect2(-20, 5));
		Button_SELECTED.shape.push_back(Vect2(20, 5));
		Button_SELECTED.shape.push_back(Vect2(20, -5));
		Button_SELECTED.shape.push_back(Vect2(-20, -5));

		Button_DOWN.shape.push_back(Vect2(-20, -5));
		Button_DOWN.shape.push_back(Vect2(-20, 5));
		Button_DOWN.shape.push_back(Vect2(20, 5));
		Button_DOWN.shape.push_back(Vect2(19, 6));
		Button_DOWN.shape.push_back(Vect2(-21, 6));
		Button_DOWN.shape.push_back(Vect2(-21, -4));
		Button_DOWN.shape.push_back(Vect2(-20, -5));
		Button_DOWN.shape.push_back(Vect2(20, -5));
		Button_DOWN.shape.push_back(Vect2(20, 5));
	}
	UI_Modle.push_back(Button_UP);
	UI_Modle.push_back(Button_SELECTED);
	UI_Modle.push_back(Button_DOWN);
}