#pragma once

#include "GameObject.h"
#include "Random.h"

class Particle:public GameObject_phy
{

public:
	Particle();
	~Particle();

	float duration;
	COLORREF color;

	void InitParticle();
	
	void Set_Shape(const std::vector<Vect2> &new_shape);

	void Update(float dt) override;
	void Draw() override;
	void DrawInCamera(const Camera &cam) override;

};