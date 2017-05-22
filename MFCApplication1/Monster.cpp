#include "stdafx.h"
#include "Monster.h"

//PNG 的pucColor[0]， pucColor[1]，pucColor[2]， pucColor[3] 共同决定一个像素颜色
//将PNG背景变透明
void Monster::TransparentPNG()
{
	for (int i = 0; i < monster.GetWidth(); i++)
		for (int j = 0; j < monster.GetHeight(); j++)
		{
			unsigned char * pucColor = reinterpret_cast<unsigned char *>(monster.GetPixelAddress(i, j));
			pucColor[0] = pucColor[0] * pucColor[3] / 255;
			pucColor[1] = pucColor[1] * pucColor[3] / 255;
			pucColor[2] = pucColor[2] * pucColor[3] / 255;
		}
}


Monster::Monster()
{
}

void Monster::Initialzation(CString name_file)
{
	//加载人物--英雄 
	monster.Load(name_file);
	TransparentPNG();

	//设置人物初始参数	
	max_frame = 2;
	frame = 0;
	direct = Left;

	x = 800;
	y = 500;
	width = 134;
	heigth = 131;

	speed = 40;
}

Monster::~Monster()
{
}
