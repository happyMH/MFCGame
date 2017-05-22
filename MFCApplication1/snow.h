#pragma once

#include "stdafx.h"
#include "Hero.h"

class Snow
{
public :
	struct each_snow
	{
		int x;
		int y;
		int number;

		each_snow() { x = 0; y = 0; }
	};
	int number;
	CImage snow_images[7];
	each_snow snows[100];

public :
	Snow();
	void Initialzation(CString * name_file, int length);
};