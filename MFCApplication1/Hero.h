#pragma once

#include "Resource.h"
#include <iostream>

//�����ĸ�����
#define Right 0
#define Left 1
#define Up 2
#define Down 3

class Hero
{
public :
	int x;                          // ������
	int y;                          //������

	CImage hero;                    //����

	int direct;                     //�����ƶ��ķ���
	int frame;                      //��ǰ���������֡��
	int max_frame;                  //�÷�������������֡��

	int width;
	int heigth;

	int speed;
	
public :
	void TransparentPNG();
public :
	Hero();
	void Initialzation(CString name_file);
	~Hero();

};
