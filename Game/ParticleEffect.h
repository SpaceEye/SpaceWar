#pragma once

#include "Particle.h"
#include <vector>

class ParticleEffect:public GameObject_phy
{
public:
	ParticleEffect(const Vect2 &pos,bool loop);
	~ParticleEffect();

	std::vector<Particle> Particles;
	float timer;
	bool IS_loop;

	int max_particles_num, produce_rate, show_num;
	float speed, duration;
	float max_range, speed_offset, dura_offset;

	

	void InitParticleEffect(
		const int &max_num,				//最大粒子数量
		const int &rate,				//粒子生成速率 个/s
		const Vect2 &dir,				//方向
		const float &max_range,			//最大发散范围
		const float &speed,				//基本速度
		const float &speed_offset,		//最大速度变化范围
		const float &dura,				//粒子生存时间
		const float &du_offset			//最大粒子生存时间变化范围
		);

	void ResetPart(const int &i);
	void Update(float dt) override;
	void Draw() override;
	void DrawInCamera(const Camera &cam) override;
};

