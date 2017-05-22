#include "stdafx.h"
#include "snow.h"

Snow::Snow()
{
}

void Snow::Initialzation(CString * name_file, int length)
{
	for (int i = 0; i < length; i++)
	{
		snow_images[i].Load(name_file[i]);
	}
	number = 20;

}
