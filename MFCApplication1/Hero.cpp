#include "stdafx.h"
#include "Hero.h"


//PNG 的pucColor[0]， pucColor[1]，pucColor[2]， pucColor[3] 共同决定一个像素颜色
//将PNG背景变透明
void Hero::TransparentPNG()
{
	for (int i = 0; i < hero.GetWidth(); i++)
		for (int j = 0; j < hero.GetHeight(); j++)
		{
			unsigned char * pucColor = reinterpret_cast<unsigned char *>(hero.GetPixelAddress(i, j));
			pucColor[0] = pucColor[0] * pucColor[3] / 255;
			pucColor[1] = pucColor[1] * pucColor[3] / 255;
			pucColor[2] = pucColor[2] * pucColor[3] / 255;
		}
}

Hero::Hero()
{

}

void Hero::Initialzation(CString name_file)
{
	//加载人物--英雄 
	hero.Load(name_file);
	TransparentPNG();

	//设置人物初始参数	
	max_frame = 2;
	frame = 0;
	direct = Left;

	x = 200;
	y = 500;
	width = 134;
	heigth = 131;

	speed = 40;
}

Hero::~Hero()
{
	
}
