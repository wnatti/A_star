#include "TileMap.h"


TileMap::TileMap(int dimension)
{
	_currentIndex = -1;
	_dimension = dimension;
	
	int tileCount = dimension*dimension;

	for (int i = 0; i < tileCount; i++)
		_mapVector.push_back('.');

}

void TileMap::writeToMap(int row, int column, char c)
{
	_mapVector[row*_dimension + column] = c;
}

void TileMap::addObstacle(int row, int column)
{
	convertVectorFriendly(row, column);
	writeToMap(row,column, 'x');
}

void TileMap::addEndingPoint(int row, int column)
{
	convertVectorFriendly(row, column);
	_endingIndex = row*_dimension + column;
	writeToMap(row, column, 'e');
}

void TileMap::addStartingPoint(int row, int column)
{
	convertVectorFriendly(row, column);
	_startingIndex = row*_dimension + column;
	writeToMap(row, column, 's');
}

void TileMap::convertVectorFriendly(int &row, int &column)
{
	row -= 1;
	column -= 1;
}

int TileMap::distanceBetweenPoints(int startR, int startC, int endR, int endC)
{
	/*convertVectorFriendly(startR, startC);
	convertVectorFriendly(endR, endC);
*/
	int horizontalDifference = startR - endR;
	horizontalDifference *= horizontalDifference;
	
	int verticalDifference = startC - endC;
	verticalDifference *= verticalDifference;

	//calculating hypotenuse
	return sqrt(verticalDifference+horizontalDifference);
}

int TileMap::getNextStep()
{
	if (_currentIndex == -1)
	_currentIndex = _startingIndex;
	

	int top = _currentIndex-_dimension;
	int topLeft = _currentIndex - _dimension - 1;
	int topRight = _currentIndex - _dimension + 1;
	int left = _currentIndex - 1;
	int right = _currentIndex + 1;
	int bot = _currentIndex + _dimension;
	int botLeft = _currentIndex + _dimension-1;
	int botRight = _currentIndex + _dimension + 1;

	int moveArea[8] = 
	{
		top, topLeft,topRight,
		left,right,
		bot,botLeft,botRight
	};

	for (int i = 0; i < 8; i++)
	{
		if (moveArea[i] == _endingIndex)
			return moveArea[i];
	}

	for (int i = 0; i < 8; i++)
	{
		
		distanceBetweenPoints()
			moveArea[i];
	}

}

void TileMap::createPath()
{

}

int TileMap::getMapRow(int index)
{
	index%_dimension
}

TileMap::~TileMap()
{
}
