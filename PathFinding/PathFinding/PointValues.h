#pragma once
class PointValues
{
private:
	char PointID[11];
	char PointNeighbors[4][11];
	int PointX[11];
	int PointY[11];

public:
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
};

