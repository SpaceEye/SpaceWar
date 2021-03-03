#include "Gun.h"

#include "ParticleEffect.h"

Gun::Gun(ShipGun_m gun_m)
{
	shape = gun_m.shape;
	CD_timer = shoot_CD;
}

Gun::~Gun() {};

void Gun::Update(float dt)
{
	if (CD_timer > 0)CD_timer -= dt;				//�������������ȴʱ��

	for (int i = 0; i < bullet.size(); i++)			//����ÿ���ӵ�
	{
		bullet[i].Update(dt);
	}
	/*����Ч��������д*/
	for (int i = 0; i < particle_effect.size(); i++)
	{
		if (particle_effect[i].max_particles_num <= 0)
		{
			particle_effect.erase(particle_effect.begin() + i);
			i--;
			continue;
		}
		particle_effect[i].Update(dt);
	}
}

void Gun::Draw()
{
	//��������
	for (unsigned int i = 0; i < shape.size(); i++)
	{
		Vect2 start = position + basic * shape[i];
		Vect2 end = position + basic * shape[(i + 1) % shape.size()];
		Draw_line(start, end);
	}
	//�ӵ�����
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i].Draw();
	}
	//����Ч������
	for (int i = 0; i < particle_effect.size(); i++)
	{
		particle_effect[i].Draw();
	}

}

void Gun::DrawInCamera(const Camera &cam)	//�����Ⱦ
{
	//��������
	Draw_Modle(shape, position - cam.position, basic);
	//�ӵ�����
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i].DrawInCamera(cam);
	}
	//����Ч������
	for (int i = 0; i < particle_effect.size(); i++)
	{
		particle_effect[i].DrawInCamera(cam);
	}
}


int Gun::Bullet_num()
{
	return bullet.size();
}

void Gun::Bullet_destroy(const int &num)
{
	//��ȷ��
	//bullet[num].~Bullet();
	bullet.erase(bullet.begin() + num);
}

void Gun::shoot()			//����
{
	if (CD_timer <= 0)
	{
		Bullet add(ShipBullet_Modle[0]);

		add.InitBullet(position, 0, bullet_speed, basic);
		bullet.push_back(add);
		CD_timer = shoot_CD;
	}
	
}