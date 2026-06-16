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
	int StartTile = 0;
	int ExitTile = 0;
	int ItemTile = 0;

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (Map[i][j] == 'S')
			{
				StartTile += 1;
			}
			else if (Map[i][j] == 'X')
			{
				ExitTile += 1;
			}
			else if (Map[i][j] == 'a' || Map[i][j] == 'b' || Map[i][j] == 'c' || Map[i][j] == 'd' || Map[i][j] == 'e' || Map[i][j] == 'f' || Map[i][j] == 'g' || Map[i][j] == 'h' || Map[i][j] == 'i' || Map[i][j] == 'j')
			{
				ItemTile += 1;
			}
		}
	}

	if (StartTile < 1 || StartTile > 1)
	{
		Valid = false;
	}
	else if (ExitTile < 1 || ExitTile > 1)
	{
		Valid = false;
	}
	else if (ItemTile < 10 || ItemTile > 10)
	{
		Valid = false;
	}

	if (!Valid)
	{
		
	}
}
