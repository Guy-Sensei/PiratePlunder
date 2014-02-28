#ifndef GRIDUTILITIES_H
#define GRIDUTILITIES_H

#pragma once
#include "..\..\Engine\Advanced2D.h"
class GridUtilities
{
public:
	static const double GridPixelWidth;
	static const double GridPixelHeight;
	GridUtilities(void);
	~GridUtilities(void);
	
	Advanced2D::Vector3 ReturnGridCordinates(Advanced2D::Vector3 SpritePosition);
	Advanced2D::Vector3 ReturnPixelCordinates(int x, int y);
};

#endif