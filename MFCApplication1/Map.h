#pragma once
#include "Resource.h"
#include <iostream>

class Map
{
public :
	CImage map;        //����ͼƬ
	int xMapStart;            //x�����ϵ�ͼ�����
	int yMapStart;
	int mapWidth;             //������ͼ�Ŀ��
	int mapHeight;            //������ͼ�ĸ߶�

public:
	Map();
	void Initialzation(CString name_file);
};
