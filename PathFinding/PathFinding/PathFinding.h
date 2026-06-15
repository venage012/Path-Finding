#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class PathFinding
{
private:
	//note: [y][x]
	char Map[20][20];

public:
	PathFinding(std::string _FileName);
	~PathFinding();

	void CheckMap();
};

