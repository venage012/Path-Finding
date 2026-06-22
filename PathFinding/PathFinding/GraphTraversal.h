#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include "PointValues.h"

class GraphTraversal
{
private:
	//note: [y][x]
	char Map[20][20];
	PointValues Points;

public:
	GraphTraversal();
	~GraphTraversal();

	void SetMap(std::string _FileName);
	void GenerateList();
	void DFS();
	void BFS();

	bool CheckMap();
};

