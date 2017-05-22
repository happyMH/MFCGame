#include "stdafx.h"
#include "Monster.h"

//PNG ��pucColor[0]�� pucColor[1]��pucColor[2]�� pucColor[3] ��ͬ����һ��������ɫ
//��PNG������͸��
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
	//��������--Ӣ�� 
	monster.Load(name_file);
	TransparentPNG();

	//���������ʼ����	
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
