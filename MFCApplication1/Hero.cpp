#include "stdafx.h"
#include "Hero.h"


//PNG ��pucColor[0]�� pucColor[1]��pucColor[2]�� pucColor[3] ��ͬ����һ��������ɫ
//��PNG������͸��
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
	//��������--Ӣ�� 
	hero.Load(name_file);
	TransparentPNG();

	//���������ʼ����	
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
