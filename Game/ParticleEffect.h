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
		const int &max_num,				//�����������
		const int &rate,				//������������ ��/s
		const Vect2 &dir,				//����
		const float &max_range,			//���ɢ��Χ
		const float &speed,				//�����ٶ�
		const float &speed_offset,		//����ٶȱ仯��Χ
		const float &dura,				//��������ʱ��
		const float &du_offset			//�����������ʱ��仯��Χ
		);

	void ResetPart(const int &i);
	void Update(float dt) override;
	void Draw() override;
	void DrawInCamera(const Camera &cam) override;
};

