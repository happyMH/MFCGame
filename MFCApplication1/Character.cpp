#include "stdafx.h"
#include "Character.h"

void Character::TransparentPNG()
{
	for (int i = 0; i < character.GetWidth(); i++)
		for (int j = 0; j < character.GetHeight(); j++)
		{
			unsigned char * pucColor = reinterpret_cast<unsigned char *>(character.GetPixelAddress(i, j));
			pucColor[0] = pucColor[0] * pucColor[3] / 255;
			pucColor[1] = pucColor[1] * pucColor[3] / 255;
			pucColor[2] = pucColor[2] * pucColor[3] / 255;
		}
}

Character::Character()
{
}


void Character::Set_Image(CString name_file)
{
	character.Load(name_file);
	TransparentPNG();
}

void Character::Reference_Center()
{
	center.x = place.x + width / 2;
	center.y = place.y + height / 2;
}



Character::~Character()
{
}
