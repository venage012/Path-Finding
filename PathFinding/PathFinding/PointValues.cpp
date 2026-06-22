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
	PointNeighbors[_Neighbor][_Position] = _nID;
}

int PointValues::GetPointID(char _Point)
{
	for (int i = 0; i < 11; i++)
	{
		if (PointID[i] == _Point)
		{
			return PointID[i];
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
	return PointNeighbors[_Neighbor][_Position];
}
