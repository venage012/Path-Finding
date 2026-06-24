#include "PointValues.h"

PointValues::PointValues()
{
}

PointValues::~PointValues()
{
}

//Sets the X & Y co-ordinates of the current point
void PointValues::SetPointsCord(int _X, int _Y, int _Position)
{
	PointX[_Position] = _X;
	PointY[_Position] = _Y;
}

//Sets the point character into the list
void PointValues::SetID(char _ID, int _Position)
{
	PointID[_Position] = _ID;
}

//Sets one of the neighbors of a selected point 
void PointValues::SetNeighbors(char _nID, int _Position, int _Neighbor)
{
	PointNeighbors[_Position][_Neighbor] = _nID;
}

//Gives the point position in integer form
int PointValues::GetPointID(char _Point)
{
	for (int i = 0; i < 11; i++)
	{
		if (PointID[i] == _Point)
		{
			return i;
		}
	}
	return 0;
}

//Returns the X co-ordinate of a point
int PointValues::GetX(int _Position)
{
	return PointX[_Position];
}

//Returns the Y co-ordinate of a point
int PointValues::GetY(int _Position)
{
	return PointY[_Position];
}

//Returns the character of a certain point
char PointValues::GetID(int _Position)
{
	return PointID[_Position];
}

//Returns one of the neighbors of a point
char PointValues::GetNeighbor(int _Position, int _Neighbor)
{
	return PointNeighbors[_Position][_Neighbor];
}

//Calculates the euclidean distance of two points
float PointValues::GetDist(int _Point1, int _Point2)
{
	//Calculates the difference of the X & Y co-ordinates of the two points
	float Total = 0;
	float XTotal = GetX(_Point1) - GetX(_Point2);
	float YTotal = GetY(_Point1) - GetY(_Point2);

	//Calculates the euclidean by the pythagoras theorem with total being c and returns to total
	Total = sqrt((XTotal * XTotal) + (YTotal * YTotal));
	return Total;
}
