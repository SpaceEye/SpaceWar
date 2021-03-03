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

void ParticleEffect::InitParticleEffect(	//����ϵͳ��ʼ��
	const int &max_num,				//�����������
	const int &rate,				//������������ ��/s
	const Vect2 &dir,				//����
	const float &max_ran,			//���ɢ��Χ
	const float &spd,				//�����ٶ�
	const float &spd_offset,		//����ٶȱ仯��Χ
	const float &dura,				//��������ʱ��
	const float &du_offset			//�����������ʱ��仯��Χ
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

void ParticleEffect::DrawInCamera(const Camera &cam)	//�����Ⱦ
{
	for (int i = 0; i < show_num; i++)
	{
		Particles[i].DrawInCamera(cam);
	}
	setlinecolor(WHITE);
}