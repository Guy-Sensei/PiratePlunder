#include "GridUtilities.h"

const double GridUtilities::GridPixelHeight = 32;
const double GridUtilities::GridPixelWidth = 32;

GridUtilities::GridUtilities(void)
{
}


GridUtilities::~GridUtilities(void)
{
}



//We assume you are passing a co-ordinate where 1 pixel = 1 unit.
Advanced2D::Vector3 GridUtilities::ReturnGridCordinates(Advanced2D::Vector3 SpritePosition)
{
	Advanced2D::Vector3  newVector(0,0,0);
	double y = SpritePosition.getY();
	double x = SpritePosition.getX();
	x = x/GridPixelWidth; //translates pixels into grid
	y=  y/GridPixelHeight; //translates pixels into grid
	x = floor(x);//Rounds to top left grid
	y = floor(y); //Rounds to top left grid
	
	newVector.setX (x);
	newVector.setY (y);

	return newVector;
}


//Returns the nearest grid from the top left orientation
Advanced2D::Vector3 GridUtilities::ReturnPixelCordinates(int x, int y)
{
	Advanced2D::Vector3  newVector(0,0,0);
	double m_X = double(x);
	double m_Y = double(y);

	m_X = m_X * GridPixelHeight;
	m_Y = m_Y * GridPixelHeight;

	newVector.setX (m_X);
	newVector.setY (m_Y);

	return newVector;
}


