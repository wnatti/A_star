#pragma once
#include <vector>

class TileMap
{
public:
	TileMap(int dimensions);
	void addObstacle(int row, int column);
	void addStartingPoint(int row, int column);
	void addEndingPoint(int row, int column);
	void createPath();
	
	~TileMap();
private:
	void writeToMap(int row, int column, char c);
	int distanceBetweenPoints(int startR, int startC, int endR, int endC);
	int getNextStep();
	std::vector<char>_mapVector;
	int _dimension;
	int _startingIndex;
	int _endingIndex;
	int _currentIndex;
	void convertVectorFriendly(int &row, int &column);
	int getMapRow(int index);
	int getMapColumn(int index);

};

