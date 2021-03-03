#include "GameObject.h"


/*********************************************************************GameObject*******************************************************************/

GameObject::GameObject():rotate_ang(0){}
GameObject::~GameObject() {}

void GameObject::Update(float dt) {}
void GameObject::Draw() {}
void GameObject::DrawInCamera(const Camera &cam) {}

void GameObject::MoveTo(const Vect2 &pos)
{
	position = pos;
}

void GameObject::RotateTo(const float &ang)
{
	rotate_ang = ang;
	Rotate(0.0f);
}

void GameObject::Rotate(const float &ang)
{
	rotate_ang += ang;
	if (rotate_ang > 360.0f)rotate_ang -= 360.0f;
	if (rotate_ang < 0.0f)rotate_ang += 360.0f;
	Matrix2 m;
	basic = m.Rotation(rotate_ang / 180.0f*PI);
}


/*********************************************************************GameObject_phy*******************************************************************/

GameObject_phy::GameObject_phy() {}
GameObject_phy::~GameObject_phy() {}

void GameObject_phy::physical_Move(float dt)
{
	dt /= 1000;
	position = position + velocity * dt + acceleration * (dt*dt*0.5);
	velocity = velocity + acceleration * dt;
}

void GameObject_phy::physical_Rotate(float dt)
{
	dt /= 1000;
	Rotate(rotate_speed * dt);
}


/*************************************************************************************************************************************************************/
