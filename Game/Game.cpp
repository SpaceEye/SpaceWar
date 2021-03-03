#include "Game.h"
#include "ctime"

#include <iostream>



using namespace std;
int timer = 0;
int max_enemy_num = 300;
int score = 0, total_time = 0;
HWND hWnd;


//��ײ��� ֮���
bool Game::Wall_Collision(float dt)
{
	bool IS_collide = false;
	for (int i = 0; i < wall->size() && !IS_collide; ++i)
	{
		Vect2 start = wall->get(i);
		Vect2 end = wall->get((i + 1) % wall->size());

		Vect2 line = end - start;
		Vect2 unit_vect = line.normalized();
		Vect2 norm = unit_vect.perCW();
		Vect2 bp = MyShip->position + MyShip->velocity *(dt/1000*0.5) - start;

		float d = bp.dot(norm);

		/*Vect2 p2 = MyShip->position + MyShip->velocity *(dt*0.5);
		p2 = p2 - start;
		Vect2 norm2 = unit_vect.perCCW();
		float d2 = p2.dot(norm2);*/

		IS_collide = d < 1;
		if (IS_collide)
		{
			int c = 1;
			Vect2 vel_now = MyShip->velocity;
			Vect2 vel_next = vel_now - norm * ((1 + c)*vel_now.dot(norm));


			MyShip->position = MyShip->position + MyShip->velocity *(dt / 1000 * 0.5) - norm * (d - 1);
			MyShip->velocity = vel_next * 0.8f;
			return IS_collide;
		}
	}

}

bool Game::Ship_Collision(float dt)
{
	bool IS_collide = false;
	
	for (unsigned int i = 0; i < enemys.size(); i++)
	{
		if ((enemys[i].position - MyShip->position).vectorLengthSquared() < 2500)
		{
			IS_collide = true;
			score--;
			MyShip->Health_Point -= 10;
			enemys.erase(enemys.begin() + i--);
			
		}
	}

	return IS_collide;
}

void Game::Bullet_Collision(float dt)
{
	bool IS_collide = false;
	for (int j = 0; j < MyShip->gun->Bullet_num(); j++)
	{
		IS_collide = false;
		for (int i = 0; i < wall->size() && !IS_collide; ++i)
		{
			Vect2 start = wall->get(i);
			Vect2 end = wall->get((i + 1) % wall->size());

			Vect2 line = end - start;
			Vect2 unit_vect = line.normalized();
			Vect2 norm = unit_vect.perCW();

			Vect2 bp = MyShip->gun->bullet[j].position + MyShip->gun->bullet[j].velocity * (dt / 1000)-start;
			float d = bp.dot(norm);

			/*Vect2 norm2 = unit_vect.perCCW();
			Vect2 p2 = MyShip->gun->bullet[j].position + MyShip->gun->bullet[j].velocity * (dt / 1000);
			p2 = p2 - start;
			float d2 = p2.dot(norm2);*/

			IS_collide = d < 0;


			if (IS_collide)//MyShip->gun->Bullet_destroy(j);
			{
				Vect2 par_pos;
				//λ�û�������
				par_pos = MyShip->gun->bullet[j].position - norm * d;
				ParticleEffect Bullet_ParEffect(MyShip->gun->bullet[j].position, false);
				Bullet_ParEffect.InitParticleEffect(
					50,				//�����������
					500,			//������������ ��/s
					norm,			//����
					90.0f,			//���ɢ��Χ
					500.0f,			//�����ٶ�
					100.0f,			//����ٶȱ仯��Χ
					100.0f,			//��������ʱ��
					10.0f			//�����������ʱ��仯��Χ
				);
				MyShip->gun->particle_effect.push_back(Bullet_ParEffect);

				MyShip->gun->Bullet_destroy(j);

				/*int c = 1;
				Vect2 vel_now = MyShip->gun->bullet[j].velocity;
				Vect2 vel_next = vel_now - norm * ((1 + c)*vel_now.dot(norm));
				Vect2 y_vel = vel_next.normalized();
				Vect2 x_vel = y_vel.perCCW();
				Matrix2 m(
					Vect2(x_vel.x, y_vel.x),
					Vect2(x_vel.y, y_vel.y)
				);
				MyShip->gun->bullet[j].basic = m;;

				MyShip->gun->bullet[j].velocity= vel_next;*/

			}
		}
	}


	for (int i = 0; i < MyShip->gun->Bullet_num(); i++)
	{
		for (unsigned int j = 0; j < enemys.size(); j++)
		{
			Vect2 Bullet_line = MyShip->gun->bullet[i].velocity * (dt / 1000);
			Vect2 p_next = MyShip->gun->bullet[i].position + MyShip->gun->bullet[i].velocity * (dt / 1000);
			Vect2 norm = Bullet_line.normalized().perCW();
			float d = (enemys[j].position - MyShip->gun->bullet[i].position).dot(norm);
			float x1= (enemys[j].position - MyShip->gun->bullet[i].position).dot(Bullet_line);
			float x2 = (enemys[j].position - p_next).dot(Bullet_line);
			if (abs(d) < 15 && x1*x2 <= 0)
			{
				score++;

				ParticleEffect Bullet_ParEffect(enemys[j].position, false);
				Bullet_ParEffect.InitParticleEffect(
					50,				//�����������
					500,				//������������ ��/s
					Vect2(0, -1),	//����
					180.0f,			//���ɢ��Χ
					500.0f,			//�����ٶ�
					100.0f,			//����ٶȱ仯��Χ
					100.0f,			//��������ʱ��
					10.0f			//�����������ʱ��仯��Χ
				);
				MyShip->gun->particle_effect.push_back(Bullet_ParEffect);
				MyShip->gun->Bullet_destroy(i--);
				enemys.erase(enemys.begin() + j--);
				break;

			}
		}
	}
}

void Show_Ship_Msg()
{

}


Game::Game(int window_Width,int window_Height)
{
	RECT rect;
	hWnd = initgraph(window_Width, window_Height);
	SetWindowPos(hWnd, HWND_TOP, 10, 10, 0, 0, SWP_NOSIZE);
	GetClientRect(hWnd, &rect);
	cxClient = rect.right - rect.left;  // ��ÿͻ������
	cyClient = rect.bottom - rect.top;  // ��ÿͻ����߶�
	Center_Pos = Vect2(cxClient / 2, cyClient / 2);
	setorigin(cxClient / 2, cyClient / 2);
	GmaeInit();
}

Game::~Game()
{
	delete MyShip;
	delete wall;
}

int Game::ShowMenu()
{
	BeginBatchDraw();

	while (1)
	{
		cleardevice();
		settextcolor(RGB(255, 255, 255));
		settextstyle(160, 0, _T("����"));
		Show_Text(Vect2(0, 200), _T("̫�մ�ս"));

		settextstyle(100, 0, _T("����"));

		Vect2 mouse_pos = GetMousePos() - Center_Pos;
		mouse_pos.y = -mouse_pos.y;

		if (mouse_pos.x > -240 && mouse_pos.x < 240 && mouse_pos.y > -60 && mouse_pos.y < 60)
		{
			Draw_Modle(UI_Modle[BUTTON_SELECTED].shape, Vect2(15, -15), Matrix2(), 12.0f, true);
			settextcolor(RGB(255, 0, 0));

			Show_Text(Vect2(12, -12), _T("��ʼ��Ϸ"));
		}
		else
		{
			Draw_Modle(UI_Modle[BUTTON_UP].shape, Vect2(0, 0), Matrix2(), 12.0f, false);
			settextcolor(RGB(255, 255, 255));
			Show_Text(Vect2(0, 0), _T("��ʼ��Ϸ"));
		}
		
		

		if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
			if (mouse_pos.x > -240 && mouse_pos.x < 240 && mouse_pos.y > -60 && mouse_pos.y < 60)
				break;

		FlushBatchDraw();
		Sleep(10);
	}
	
	EndBatchDraw();
	settextcolor(RGB(255, 255, 255));
	settextstyle(16, 0, _T("����"));
	return 0;
}

//��Ϸ��ʼ��
void Game::GmaeInit()
{


	//��������ģ��
	Modle_Load();
	//���������
	cam = new Camera;
	//����ɴ�ģ��
	MyShip = new SpaceShip(SpaceShip_Modle[0]);
	//�����ͼģ��
	wall = new Wall;
	//���뱳��

	SpaceShip s(SpaceShip_Modle[0]);
	obj.push_back(s);

	//��ʼ���ɴ�λ��
	MyShip->InitSpaceShip(Vect2(0, 0));
	Ship_obj_pos = Vect2(0, 0);
	//��ʼ�������
	Random::randInit();
	
}


//��Ϸ���ݸ���
void Game::Game_Update(float dt)
{
	//��ʱ��
	timer += dt;
	total_time += dt;

	//��������Ϣ����
	Key_Msg_proc();
	Mouse_Msg_proc();

	//������ײ��
	Wall_Collision(dt);
	//�ӵ���ײ��
	Bullet_Collision(dt);
	//�ɴ���ײ��
	Ship_Collision(dt);

	
	//������������
	int race = 500;
	//���ɵ���
	if (timer > race && enemys.size() <= max_enemy_num)
	{
		int add_num = (timer / race < max_enemy_num - enemys.size()) ? timer / race : max_enemy_num - enemys.size();
		for (int i = 0; i < add_num; i++)
		{
			Vect2 p(Random::random_in(-4000, 4000), Random::random_in(-4000, 4000));
			while (p.vectorLength() < 2000)
			{
				p = Vect2(Random::random_in(-4000, 4000), Random::random_in(-4000, 4000));
			}
			Enemy e(Enemy_Modle[(int)Random::random_in(1, 100) % Enemy_Modle.size()]);
			e.position = MyShip->position + p;
			enemys.push_back(e);
		}
		timer = 0;
	}
	//�������ݸ���
	for (unsigned int i = 0; i < enemys.size(); i++)
	{
		
		Vect2 direction = MyShip->position - enemys[i].position;
		Vect2 y_basis = direction.normalized();
		Vect2 x_basis = y_basis.perCW();
		enemys[i].basic = Matrix2(
			Vect2(x_basis.x, y_basis.x),
			Vect2(x_basis.y, y_basis.y)
		);
		enemys[i].velocity = y_basis.normalized()*200.0f;

		enemys[i].Update(dt);
	}

	//���ٿ�������Ŀ��λ��
	Vect2 direction = Ship_obj_pos - MyShip->position;
	IS_to_obj = direction.vectorLengthSquared() > 6000;
	if (IS_to_obj)
	{

		float ang = (MyShip->basic.Get_V1().dot(direction)) / (MyShip->basic.Get_V2().vectorLength()*direction.vectorLength());
		if (ang > 0.04)MyShip->Right_Rotate();
		if (ang < -0.04)MyShip->Left_Rotate();
		MyShip->Move_Forward();
	}
	else
	{
		Ship_obj_pos = MyShip->position;
		//MyShip->Brake();
		//MyShip->velocity = MyShip->velocity*(direction.vectorLengthSquared() / 4000.0f);
	}

	MyShip->Update(dt);
	cam->position = MyShip->position;
	//obj[0].Update(dt);
}


//��Ϸͼ����Ⱦ
void Game::Game_Draw()
{
	
	cleardevice();
	

	TCHAR fps[50];
	wsprintf(fps, L"FPS:%d  Score:%d  Time:%ds  HP:%d", FPS, score, total_time / 1000, (int)MyShip->Health_Point);
	outtextxy(-cxClient / 2, -cyClient / 2, fps);

	if (IS_to_obj)
	{
		Draw_line(MyShip->position - cam->position, Ship_obj_pos - cam->position);
	}

	//wall->Draw();
	wall->DrawInCamera(*cam);
	

	for (unsigned int i = 0; i < enemys.size(); i++)
	{
		//enemys[i].Draw();
		enemys[i].DrawInCamera(*cam);
	}
	//MyShip->Draw();
	MyShip->DrawInCamera(*cam);
	//obj[0].Draw();


	
}
void Game::GameLoop()
{
	
	ShowMenu();

	

	/**********************************/
	int i = 0;
	clock_t start, end ,end1, start1;
	float dt = 0;
	start = clock();
	start1 = start;
	/**********************************/
	//��ѭ��
	BeginBatchDraw();
	while (1)
	{
		if (MyShip->Health_Point <= 0)break;
		//��Ϸ���ݸ���
		Game_Update(dt);
		//��Ϸ��Ⱦ
		Game_Draw();
		//��ʾ��Ⱦͼ��
		FlushBatchDraw();
		
		//֡������**************************************************************
		end1 = clock();
		while (end1 - start1 <= 1000.0 / 120.0) { end1 = clock(); Sleep(1); }
		start1 = clock();
		//***********************************************************************

		//����֡��**************************************************************
		i++;
		if (i == 10)
		{

			end = clock();
			i = 0;
			
			dt = (float)((end - start) / 10.0);
			FPS = (int)(1000.0 / dt);
			start = clock();
		}
		//***********************************************************************
		
		//Sleep(5);
	}
	EndBatchDraw();
	settextstyle(160, 0, _T("����"));
	Show_Text(Vect2(0, 0), _T("��Ϸ����"));
	while (true) Sleep(10000);
}

void Game::Key_Msg_proc()		//������Ϣ������
{
	/***********************���̿���*******************/
	if (GetAsyncKeyState('W') & 0x8000)
	{
		MyShip->Move_Forward();
		Ship_obj_pos = MyShip->position;
	}
	else if (GetAsyncKeyState('S') & 0x8000)
	{
		MyShip->Move_Backward();
		Ship_obj_pos = MyShip->position;
	}
	else
	{
		MyShip->Stop_Accelerate();
	}

	if (GetAsyncKeyState('A') & 0x8000)
	{
		MyShip->Left_Rotate();
		Ship_obj_pos = MyShip->position;
	}
	else if (GetAsyncKeyState('D') & 0x8000)
	{
		MyShip->Right_Rotate();
		Ship_obj_pos = MyShip->position;
	}
	else
	{
		MyShip->Stop_Rotate();
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000)
	{
		MyShip->Brake();
	}

	
}

void Game::Mouse_Msg_proc()		//�����Ϣ������
{
	Vect2 mouse_pos = GetMousePos() - Center_Pos;
	mouse_pos.y = -mouse_pos.y;
	mouse_pos = mouse_pos + cam->position;
	Vect2 direction = mouse_pos - MyShip->position;
	Vect2 y_basis = direction.normalized();
	Vect2 x_basis = y_basis.perCW();
	Matrix2 new_bas(
		Vect2(x_basis.x, y_basis.x),
		Vect2(x_basis.y, y_basis.y)
	);
	//������������
	MyShip->Set_gun_orientation(new_bas);

	//�����ӵ�
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000)
	{
		MyShip->Shoot();
	}

	//���ٿطɴ�
	if (GetAsyncKeyState(VK_RBUTTON) & 0x8000)
	{
		Ship_obj_pos = mouse_pos;
		IS_to_obj = true;
	}


	
	
}