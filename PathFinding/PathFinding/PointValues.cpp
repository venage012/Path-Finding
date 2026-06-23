#include "PointValues.h"

PointValues::PointValues()
{
}

PointValues::~PointValues()
{
}

void PointValues::SetPointsCord(int _X, int _Y, int _Position)
{
	PointX[_Position] = _X;
	PointY[_Position] = _Y;
}

void PointValues::SetID(char _ID, int _Position)
{
	PointID[_Position] = _ID;
}

void PointValues::SetNeighbors(char _nID, int _Position, int _Neighbor)
{
	PointNeighbors[_Position][_Neighbor] = _nID;
}

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

int PointValues::GetX(int _Position)
{
	return PointX[_Position];
}

int PointValues::GetY(int _Position)
{
	return PointY[_Position];
}

char PointValues::GetID(int _Position)
{
	return PointID[_Position];
}

char PointValues::GetNeighbor(int _Position, int _Neighbor)
{
	return PointNeighbors[_Position][_Neighbor];
}

float PointValues::GetDist(int _Point1, int _Point2)
{
	float Total = 0;
	float XTotal = GetX(_Point1) - GetX(_Point2);
	float YTotal = GetY(_Point1) - GetY(_Point2);

	Total = sqrt((XTotal * XTotal) + (YTotal * YTotal));
	return Total;
}
