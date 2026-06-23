#pragma once
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include "PointValues.h"

class GraphTraversal
{
private:
	//note: [y][x]
	char Map[20][20];
	float Matrix[11][11];
	PointValues Points;

public:
	GraphTraversal();
	~GraphTraversal();

	bool SetMap(std::string _FileName);
	void PrintMap();
	void GenerateMatrix();
	void DFS();
	void DFSRec(bool _Visited[], int _PointID, std::vector<int> _Result);
	void BFS();

	bool CheckMap();
};

