#include "GraphTraversal.h"

GraphTraversal::GraphTraversal()
{
}

GraphTraversal::~GraphTraversal()
{
}

void GraphTraversal::SetMap(std::string _FileName)
{
	std::fstream Load;
	std::string Save;

	std::string CurrentTile;
	int Pointid = 0;

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
				if (CurrentTile == "s" ||
					CurrentTile == "a" ||
					CurrentTile == "b" ||
					CurrentTile == "c" ||
					CurrentTile == "d" ||
					CurrentTile == "e" ||
					CurrentTile == "f" ||
					CurrentTile == "g" ||
					CurrentTile == "h" ||
					CurrentTile == "i" ||
					CurrentTile == "j"  )
				{
					Points.SetID(CurrentTile[0], Pointid);
					Points.SetPointsCord(j, i, Pointid);
				}
				Save.erase(0, 1);
			}
		}
	}

	for (int ID = 0; ID < 11; ID++)
	{
		int IDX = Points.GetX(ID);
		int IDY = Points.GetY(ID);
		int Neighbors = 0;

		for (int i = IDY; i < 0; i--)
		{
			for (int j = IDX; j < 0; i--)
			{

			}
		}
	}
}

void GraphTraversal::GenerateList()
{
}

void GraphTraversal::DFS()
{
}

void GraphTraversal::BFS()
{
}

bool GraphTraversal::CheckMap()
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
		std::cout << "Error: There is an invalid amount of Start tiles" << std::endl;
		Valid = false;
	}
	else if (ExitTile < 1 || ExitTile > 1)
	{
		std::cout << "Error: There is an invalid amount of Exit tiles" << std::endl;
		Valid = false;
	}
	else if (ItemTile < 10 || ItemTile > 10)
	{
		std::cout << "Error: There is an invalid amount of Item tiles" << std::endl;
		Valid = false;
	}


    return Valid;
}
