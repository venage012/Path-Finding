#include "GraphTraversal.h"

GraphTraversal::GraphTraversal()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			Map[i][j] = '.';
		}
	}
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			Matrix[i][j] = 0.0f;
		}
	}
}

GraphTraversal::~GraphTraversal()
{
}

bool GraphTraversal::SetMap(std::string _FileName)
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
					Pointid++;
				}
				Save.erase(0, 1);
			}
		}
	}

	PrintMap();
	if (!CheckMap())
	{
		return false;
	}

	for (int k = 0; k < 11; k++)
	{
		int Node[2] = { -1,-1 };
		float Dist[2] = { -1.0,-1.0 };

		for (int l = 0; l < 11; l++)
		{
			if (k == l)
			{
				continue;
			}
			float EucDist = Points.GetDist(k, l);

			if (Node[0] == -1 || EucDist < Dist[0])
			{
				Node[1] = Node[0];
				Dist[1] = Dist[0];
				Node[0] = l;
				Dist[0] = EucDist;
			}
			else if (Node[1] == -1 || EucDist < Dist[0])
			{
				Node[1] = l;
				Dist[1] = EucDist;
			}
		}

		Points.SetNeighbors(Points.GetID(Node[0]), k, 0);
		Points.SetNeighbors(Points.GetID(Node[1]), k, 1);

		for (int m = 0; m < 2; m++)
		{
			int Neighbor = Node[m];
			float NearDist = Dist[m];

			Matrix[Neighbor][k] = NearDist;
			Matrix[k][Neighbor] = NearDist;
		}
	}
	return true;
}

void GraphTraversal::PrintMap()
{
}

void GraphTraversal::GenerateMatrix()
{
	for (int i = 0; i < 11; i++)
	{
		for (int j = 0; j < 11; j++)
		{
			std::cout << std::fixed << std::setprecision(2)<< Matrix[i][j] << ", ";
		}
		std::cout << std::endl;
	}
}

void GraphTraversal::DFS()
{
	bool Visited[11];
	std::vector<int> Results;
	for (int i = 0; i < 11; i++)
	{
		Visited[i] = false;
	}

	DFSRec(Visited, 0, Results);

	for (int i = 0; i < Results.size(); i++)
	{
		std::cout << Results[i] << " -> ";
	}
	std::cout << std::endl;
}

void GraphTraversal::DFSRec(bool _Visited[], int _PointID, std::vector<int> _Result)
{
	_Visited[_PointID] = true;

	_Result.push_back(_PointID);

	for (int i = 0; i < 2; i++)
	{
		int Neighbor = Points.GetPointID((Points.GetNeighbor(_PointID, i)));
		if (_Visited[Neighbor] == false)
		{
			DFSRec(_Visited, _PointID, _Result);
		}
	}
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
			if (Map[i][j] == 's')
			{
				StartTile += 1;
			}
			else if (Map[i][j] == 'x')
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
