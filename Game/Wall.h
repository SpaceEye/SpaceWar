#pragma once

#include "GameObject.h"


class Wall:public GameObject
{
private:

public:
	Wall();
	~Wall();
	int size();
	Vect2 get(int i);

	void Update(float dt) override;
	void Draw() override;
	void DrawInCamera(const Camera &cam) override;

};
