#pragma once
#include <graphics.h>
#include "Vect2.h"
#include "Vect3.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include <vector>

#define PI 3.141592653589793238462643383249901429

void Draw_line(Vect2 start, Vect2 end);
void Show_Text(const Vect2 &position, const LPCTSTR &text);
void Draw_Modle(std::vector<Vect2> modle, Vect2 position, Matrix2 rotate, float scale = 1.0f, bool IS_loop = true);
void Draw_UI(std::vector<Vect2> modle, Vect2 position, Matrix2 rotate, float scale = 1.0f, bool IS_loop = true);
Vect2 GetMousePos();
