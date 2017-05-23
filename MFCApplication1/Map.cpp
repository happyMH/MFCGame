#include "stdafx.h"
#include "Map.h"

Map::Map()
{

}

void Map::Initialzation(CString name_file)
{
	map.Load(name_file);
	mapWidth = map.GetWidth();
	mapHeight = map.GetHeight();
	xMapStart = 0;
	yMapStart = 0;
}
