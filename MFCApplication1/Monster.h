#pragma once

#include "Resource.h"
#include <iostream>
#include "ChildView.h"

//�����ĸ�����
#define Right 0
#define Left 1
#define Up 2
#define Down 3

class Monster
{
public:
	int x;                          // ������
	int y;                          //������

	CImage monster;                    //����

	int direct;                     //�����ƶ��ķ���
	int frame;                      //��ǰ���������֡��
	int max_frame;                  //�÷�������������֡��

	int width;
	int heigth;

	int speed;

public:
	void TransparentPNG();
public:
	Monster();
	void Initialzation(CString name_file);
	~Monster();

};