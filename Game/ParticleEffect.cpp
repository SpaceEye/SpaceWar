#include "ParticleEffect.h"





ParticleEffect::ParticleEffect(const Vect2 &pos, bool loop):IS_loop(loop), show_num(0), timer(0)
{
	position = pos;
}

ParticleEffect::~ParticleEffect()
{
	
}

void ParticleEffect::ResetPart(const int &i)
{
	Particles[i].position = position;
	Matrix2 m;
	m = basic.Rotation(Random::random_in(-max_range, max_range) / 180.0f*PI);
	float spd = speed + Random::random_in(-speed_offset, speed_offset);
	Particles[i].velocity = velocity + m * (basic * (Vect2(0, 1) * spd));
	Particles[i].duration = 0;
}

void ParticleEffect::InitParticleEffect(	//粒子系统初始化
	const int &max_num,				//最大粒子数量
	const int &rate,				//粒子生成速率 个/s
	const Vect2 &dir,				//方向
	const float &max_ran,			//最大发散范围
	const float &spd,				//基本速度
	const float &spd_offset,		//最大速度变化范围
	const float &dura,				//粒子生存时间
	const float &du_offset			//最大粒子生存时间变化范围
)
{
	max_particles_num = max_num;
	speed = spd;
	produce_rate = rate;
	duration = dura;
	max_range = max_ran;
	speed_offset = spd_offset;
	dura_offset = du_offset;
	Vect2 temp = dir;
	Vect2 y_dir = temp.normalized();
	Vect2 x_dir = y_dir.perCW();
	basic = Matrix2(
		Vect2(x_dir.x, y_dir.x),
		Vect2(x_dir.y, y_dir.y)
	);

	for (int i = 0; i < max_particles_num; i++)
	{
		Particle p;
		Particles.push_back(p);
	}

	for (int i = 0; i < max_particles_num; i++)
	{
		ResetPart(i);
	}

}

void ParticleEffect::Update(float dt)
{
	timer += dt;
	if ((timer > (1000 / produce_rate)) && show_num <= max_particles_num)
	{
		show_num += timer / (1000 / produce_rate);
		show_num = (show_num < max_particles_num) ? show_num : max_particles_num;
		timer = 0;
	}

	for (int i = 0; i < show_num; i++)
	{
		Particles[i].duration += dt;
		
		if (Particles[i].duration > duration + Random::random_in(-dura_offset, dura_offset))
		{
			if (IS_loop)
			{
				ResetPart(i);
			}
			else
			{
				Particles.erase(Particles.begin() + i--);
				max_particles_num--;
				show_num--;
				continue;
			}
		}
		Particles[i].Update(dt);
	}
}


void ParticleEffect::Draw()
{
	for (int i = 0; i < show_num; i++)
	{
		Particles[i].Draw();
	}
	setlinecolor(WHITE);
}

void ParticleEffect::DrawInCamera(const Camera &cam)	//相机渲染
{
	for (int i = 0; i < show_num; i++)
	{
		Particles[i].DrawInCamera(cam);
	}
	setlinecolor(WHITE);
}