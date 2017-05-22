#pragma once

#include "Resource.h"
#include <iostream>

//定义四个方向
#define Right 0
#define Left 1
#define Up 2
#define Down 3

class Hero
{
public :
	int x;                          // 横坐标
	int y;                          //纵坐标

	CImage character;                    //人物

	int direct;                     //人物移动的方向
	int frame;                      //当前方向人物的帧数
	int max_frame;                  //该方向上人物最大的帧数

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
