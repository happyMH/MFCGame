#pragma once

#include "Resource.h"
#include <iostream>

//�����ĸ�����
#define Right 0
#define Left 1
#define Up 2
#define Down 3

class Character
{
public:
	POINT place;
	POINT center;

	CImage character;                //����

	int direct;                     //�����ƶ��ķ���
	int frame;                      //��ǰ���������֡��
	int max_frame;                  //�÷�������������֡��

	int width;
	int height;

	int speed;

private:
	void TransparentPNG();
public:
	Character();
	void Set_Image(CString name_file);
	void Reference_Center();

	~Character();
};