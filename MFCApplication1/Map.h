#pragma once
#include "Resource.h"
#include <iostream>

class Map
{
public :
	CImage backGround;        //����ͼƬ
	int xMapStart;            //x�����ϵ�ͼ�����
	int mapWidth;             //������ͼ�Ŀ��

public:
	Map();
	void Initialzation(CString name_file);
};
