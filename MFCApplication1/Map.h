#pragma once
#include "Resource.h"
#include <iostream>

class Map
{
public :
	CImage backGround;        //背景图片
	int xMapStart;            //x方向上地图的起点
	int mapWidth;             //背景地图的宽度

public:
	Map();
	void Initialzation(CString name_file);
};
