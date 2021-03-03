#include "tool.h"


//画线
void Draw_line(Vect2 start, Vect2 end)
{
	line(start.x, -start.y, end.x, -end.y);
}

//显示字
void Show_Text(const Vect2 &position, const LPCTSTR &text)
{
	LOGFONT font;
	gettextstyle(&font);
	LONG x_offset = (font.lfWidth ? font.lfWidth : font.lfHeight) * lstrlen(text) / 2;
	LONG y_offset = font.lfHeight / 2;
	outtextxy(position.x - x_offset, -(position.y + y_offset), text);
}

//模型渲染
void Draw_Modle(std::vector<Vect2> modle, Vect2 position, Matrix2 rotate, float scale, bool IS_loop)
{
	if(IS_loop)
		for (unsigned int i = 0; i < modle.size(); i++)
		{
			Vect2 start = position + rotate * modle[i]* scale;
			Vect2 end = position + rotate * modle[(i + 1) % modle.size()]* scale;
			Draw_line(start, end);
		}
	else
		for (unsigned int i = 0; i < modle.size() - 1; i++)
		{
			Vect2 start = position + rotate * modle[i]* scale;
			Vect2 end = position + rotate * modle[i + 1]* scale;
			Draw_line(start, end);
		}
}

//UI渲染
void Draw_UI(std::vector<Vect2> UI, Vect2 position, Matrix2 rotate, float scale, bool IS_loop)
{

}

//获得鼠标位置
Vect2 GetMousePos()
{
	LPPOINT p;
	p = new POINT;
	GetCursorPos(p);
	ScreenToClient(GetForegroundWindow(), p);
	Vect2 pos = Vect2((*p).x, (*p).y);
	delete p;
	return pos;
}

