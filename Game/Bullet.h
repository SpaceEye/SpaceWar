#pragma once

#include "GameObject.h"
#include "Modle.h"

class Bullet : public GameObject_phy
{
public:
	Bullet(ShipBullet_m bullet_m);
	~Bullet();

	float power;

	void InitBullet(const Vect2 &pos, const float &pow, const float &speed, const Matrix2 &bas);
	void Update(float dt) override;
	void Draw() override;
	void DrawInCamera(const Camera &cam) override;

private:


};