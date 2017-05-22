#include "stdafx.h"
#include "Map.h"

Map::Map()
{

}

void Map::Initialzation(CString name_file)
{
	backGround.Load(name_file);
	mapWidth = backGround.GetWidth();
	xMapStart = 0;
}
