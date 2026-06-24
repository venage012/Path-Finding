/**************************************************************************
<Bachelor of Software Engineering (Games Development)>
Media Design School
Auckland
New Zealand
(c) <2026> Media Design School
File Name : <PointValues.h>
Description : <Stores and sends the data of traversal points>
Author : <Liam Aumareva>
Mail : <liam.aumareva@mds.ac.nz>
**************************************************************************/
#pragma once
#include <cmath>
#include <iostream>
class PointValues
{
private:
	//Arrays for the saved points
	//0 = 's', 1 = 'a', 2 = 'b', etc
	char PointID[11];
	char PointNeighbors[11][2];
	int PointX[11];
	int PointY[11];

public:
	//Functions for point values
	PointValues();
	~PointValues();

	void SetPointsCord(int _X, int _Y, int _Position);
	void SetID(char _ID, int _Position);
	void SetNeighbors(char _nID, int _Position, int _Neighbor);

	int GetPointID(char _Point);
	int GetX(int _Position);
	int GetY(int _Position);
	char GetID(int _Position);
	char GetNeighbor(int _Position, int _Neighbor);

	float GetDist(int _Point1, int _Point2);
};

