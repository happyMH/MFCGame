#pragma once
#include "Resource.h"
#include <iostream>

class Map
{
public :
	CImage map;        //背景图片
	int xMapStart;            //x方向上地图的起点
	int yMapStart;
	int mapWidth;             //背景地图的宽度
	int mapHeight;            //背景地图的高度

public:
	Map();
	void Initialzation(CString name_file);
};
