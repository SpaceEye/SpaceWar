#pragma once
#include "tool.h"
#include "Camera.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

	float rotate_ang;
	

	Matrix2 basic;
	Vect2 position;

	std::vector<Vect2> shape;

	

	void MoveTo(const Vect2 &pos);
	void RotateTo(const float &ang);
	void Rotate(const float &ang);

	virtual void Update(float dt);
	virtual void Draw();
	virtual void DrawInCamera(const Camera &cam);
};


class GameObject_phy : public GameObject
{
public:
	GameObject_phy();
	~GameObject_phy();

	Vect2 velocity;
	Vect2 acceleration;
	float rotate_speed = 0;

	void physical_Move(float dt);
	void physical_Rotate(float dt);

};

