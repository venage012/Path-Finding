/*******************************************************************************
<Bachelor of Software Engineering (Games Development)>
Media Design School
Auckland
New Zealand
(c) <2026> Media Design School
File Name : <GraphTraversal.h>
Description : <Creates the map and prints out the Traversal operations (no a*)>
Author : <Liam Aumareva>
Mail : <liam.aumareva@mds.ac.nz>
********************************************************************************/
#pragma once
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include "PointValues.h"

class GraphTraversal
{
private:
	//Variables for the class
	//note: [y][x]
	char Map[20][20];
	float Matrix[11][11];
	std::vector<std::list<int> > Adjacent;
	std::vector<char> PointTitle;
	PointValues Points;

	//Private functions
	void PrintMap();
	void DFSRec(std::vector<bool>& _Visited, int _PointID, std::vector<int>& _Result);
	bool CheckMap();

public:
	//Public functions
	GraphTraversal();
	~GraphTraversal();

	bool SetMap(std::string _FileName);

	void MapReset();
	void GenerateMatrix();
	void DFS();
	void BFS();


};

