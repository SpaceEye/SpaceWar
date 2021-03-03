#pragma once
#include "GameObject.h"
#include "Bullet.h"
#include "ParticleEffect.h"
#include "Modle.h"

class Gun : public GameObject_phy
{
public:

	std::vector<Bullet> bullet;
	std::vector<ParticleEffect> particle_effect;
	float bullet_speed = 1000;
	float shoot_CD = 100;
	float CD_timer = 0;

	Gun(ShipGun_m gun_m);
	~Gun();

	void shoot();
	void Bullet_destroy(const int &num);

	int Bullet_num();

	void Update(float dt) override;
	void Draw() override;
	void DrawInCamera(const Camera &cam) override;
	

private:
	
	
};
