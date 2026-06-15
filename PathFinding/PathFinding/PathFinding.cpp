#include "PathFinding.h"

PathFinding::PathFinding(std::string _FileName)
{
	std::fstream Load;
	std::string Save;

	std::string CurrentTile;

	Load.open(_FileName, std::ios::in);

	if (Load.is_open())
	{
		for (int i = 0; i < 20; i++)
		{
			getline(Load, Save);
			for (int j = 0; j < 20; j++)
			{
				CurrentTile = Save.substr(0, 1);
				Map[i][j] = CurrentTile[0];
				Save.erase(0, 1);
			}
		}
	}
}

PathFinding::~PathFinding()
{
}

void PathFinding::CheckMap()
{
	bool Valid = true;

	if (!Valid)
	{
		
	}
}
