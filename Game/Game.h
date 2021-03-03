#pragma once

#include "GameObject.h"
#include "Modle.h"
#include "SpaceShip.h"
#include "Enemy.h"
#include "Wall.h"
#include "Gun.h"
#include "Bullet.h"
#include "ParticleEffect.h"
#include "Camera.h"



class Game
{
public:
	Game(int window_length, int window_hight);
	~Game();

	void GmaeInit();
	int ShowMenu();
	void GameLoop();


	void Game_Update(float dt);
	void Game_Draw();

	void Key_Msg_proc();
	void Mouse_Msg_proc();

private:
	int FPS;
	int cxClient, cyClient;
	float xScale, yScale;
	Vect2 Center_Pos;
	std::vector<GameObject> obj;

	Vect2 Gravity = Vect2(0, 1) * 5;
	Vect2 Ship_obj_pos;
	bool IS_to_obj = false;
	Camera *cam;
	SpaceShip *MyShip;
	Wall *wall;
	ParticleEffect *ParEffect;
	ParticleEffect *ParEffect1;
	ParticleEffect *ParEffect2;
	std::vector<Enemy> enemys;

	bool Wall_Collision(float dt);
	bool Ship_Collision(float dt);
	void Bullet_Collision(float dt);


};