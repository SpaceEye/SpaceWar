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
	if (CD_timer > 0)CD_timer -= dt;				//更新炮塔射击冷却时间

	for (int i = 0; i < bullet.size(); i++)			//更新每颗子弹
	{
		bullet[i].Update(dt);
	}
	/*粒子效果后面来写*/
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
	//炮塔绘制
	for (unsigned int i = 0; i < shape.size(); i++)
	{
		Vect2 start = position + basic * shape[i];
		Vect2 end = position + basic * shape[(i + 1) % shape.size()];
		Draw_line(start, end);
	}
	//子弹绘制
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i].Draw();
	}
	//粒子效果绘制
	for (int i = 0; i < particle_effect.size(); i++)
	{
		particle_effect[i].Draw();
	}

}

void Gun::DrawInCamera(const Camera &cam)	//相机渲染
{
	//炮塔绘制
	Draw_Modle(shape, position - cam.position, basic);
	//子弹绘制
	for (int i = 0; i < bullet.size(); i++)
	{
		bullet[i].DrawInCamera(cam);
	}
	//粒子效果绘制
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
	//待确定
	//bullet[num].~Bullet();
	bullet.erase(bullet.begin() + num);
}

void Gun::shoot()			//开火
{
	if (CD_timer <= 0)
	{
		Bullet add(ShipBullet_Modle[0]);

		add.InitBullet(position, 0, bullet_speed, basic);
		bullet.push_back(add);
		CD_timer = shoot_CD;
	}
	
}