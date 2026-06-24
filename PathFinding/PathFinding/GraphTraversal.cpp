#include "GraphTraversal.h"
#include <queue>
#include <iomanip>

//Initialises the array variables
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
	Adjacent.resize(11);
}

GraphTraversal::~GraphTraversal()
{
}

//Sets up the map
bool GraphTraversal::SetMap(std::string _FileName)
{
	//File loader variables
	std::fstream Load;
	std::string Save;
	std::string CurrentTile;
	int Pointid = 0;

	//Opens and loads the file
	Load.open(_FileName, std::ios::in);
	if (Load.is_open())
	{
		for (int i = 0; i < 20; i++)
		{
			getline(Load, Save);
			for (int j = 0; j < 20; j++)
			{
				//Takes the character from the file into the map
				CurrentTile = Save.substr(0, 1);
				Map[i][j] = CurrentTile[0];
				//If the current character is a special point or the start
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
					//Saves the point's data for use in later functions
					PointTitle.push_back(CurrentTile[0]);
					Points.SetID(CurrentTile[0], Pointid);
					Points.SetPointsCord(j, i, Pointid);
					Pointid++;
				}
				//Erases the current character so it can read the next character in the file
				Save.erase(0, 1);
			}
		}
	}

	//Prints the map and checks if it is valid
	PrintMap();
	bool Check = CheckMap();
	//If it is invalid, it will return false which is important for the checks in the main cpp
	if (Check == false)
	{
		return false;
	}

	//This is to set the points nearby neighbors
	//'k' reperesents the point currently being checked
	for (int k = 0; k < 11; k++)
	{
		//Arrays for saving the current point's neighbors and the distance between the point and neighbor
		int NeighborPoint[2] = { -1,-1 };
		float PointDistance[2] = { -1.0,-1.0 };

		//'l' represents the point that can potentially be one of the two neighbors to k
		for (int l = 0; l < 11; l++)
		{
			//Continues to next value of 'l' if the point of 'k' is the same as 'l'
			if (k == l)
			{
				continue;
			}

			//Calculates the euclidean distance between the two points
			float EuclideanDistance = Points.GetDist(k, l);

			//If there are no saved neighbors in position 1, or the calculated distance is less than the distance of the first saved neighbor
			if (NeighborPoint[0] == -1 || EuclideanDistance < PointDistance[0])
			{
				//This will push the data of neighbor 1, to the neighbor 2 position and then save the current neighbor
				NeighborPoint[1] = NeighborPoint[0];
				PointDistance[1] = PointDistance[0];
				NeighborPoint[0] = l;
				PointDistance[0] = EuclideanDistance;
			}
			//If there are no saved neighbors in position 2, or the calculated distance is less than the distance of the second saved neighbor
			else if (NeighborPoint[1] == -1 || EuclideanDistance < PointDistance[0])
			{
				//Replaces the data of neighbor 2 with the current neighbor
				NeighborPoint[1] = l;
				PointDistance[1] = EuclideanDistance;
			}
		}

		//When neighbors are set, the point data is updated to save the neighbors
		Points.SetNeighbors(Points.GetID(NeighborPoint[0]), k, 0);
		Points.SetNeighbors(Points.GetID(NeighborPoint[1]), k, 1);

		//Then the saved neighbor data is saved to the adjacent vector & the distance is saved to the adjacent matrix data
		for (int m = 0; m < 2; m++)
		{
			int Neighbor = NeighborPoint[m];
			float NearDist = PointDistance[m];
			
			Adjacent[k].push_back(Neighbor);
			Adjacent[Neighbor].push_back(k);
			Matrix[Neighbor][k] = NearDist;
			Matrix[k][Neighbor] = NearDist;
		}
	}
	//Returns true as the map has now loaded
	return true;
}

//Prints the map to the console via for loops
void GraphTraversal::PrintMap()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			std::cout << Map[i][j];
		}
		std::cout << std::endl;
	}
}

//Resets the data currently saved on the map
void GraphTraversal::MapReset()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			Map[i][j] = '.';
		}
	}
}

//Generates the adjacency matrix
void GraphTraversal::GenerateMatrix()
{
	//Prints the top of the matrix table
	std::cout << "Adjacency Matrix:" << std::endl
		 << "|   | s  | a  | b  | c  | d  | e  | f  | g  | h  | i  | j  |" << std::endl;
	//Loops through the matrix data and displays it on the console
	for (int i = 0; i < 11; i++)
	{
		std::cout << "| " << PointTitle[i] << " |";
		for (int j = 0; j < 11; j++)
		{
			std::cout << std::fixed << std::setprecision(2)<< Matrix[i][j] << "|";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//Depth-first search
void GraphTraversal::DFS()
{
	//Creates vectors for search function
	std::vector<bool> Visited(Adjacent.size(),false);
	std::vector<int> Results;

	//Begins the recursion
	DFSRec(Visited, 0, Results);

	//When recursion ends, it prints out the reultant search data
	std::cout << "Depth-first search:" << std::endl;
	for (int i = 0; i < Results.size(); i++)
	{
		std::cout << Points.GetID(Results[i]) << " -> ";
	}
	std::cout << "End" << std::endl << std::endl;
}

//Depth-first search reccursion code
void GraphTraversal::DFSRec(std::vector<bool>& _Visited, int _PointID, std::vector<int>& _Result)
{
	//Current point is being visted now, so its visited data is set to true on the vector
	_Visited[_PointID] = true;
	//Pushes back the visited point to the result
	_Result.push_back(_PointID);

	//Sets 'i' to be the one of the neighbors for the '_PointID'
	for (int i : Adjacent[_PointID])
	{
		//If the neighbor hasnt been visited yet, recurse to visted the neighbor
		if (_Visited[i] == false)
		{
			DFSRec(_Visited, i, _Result);
		}
	}
}

//Breadth first search
void GraphTraversal::BFS()
{
	//Variables for the search function
	std::vector<bool> Visited(Adjacent.size(), false);
	std::vector<int> Result;
	std::queue<int> Queue;
	int Start = 0;

	//Visits the start point, and pushes the start node to queue
	Visited[Start] = true;
	Queue.push(Start);

	//Loops while the queue is not empty
	while (!Queue.empty())
	{
		//Puts the first value of queue into 'current'
		//Pops the value out of queue
		//Pushes back 'current' into the result vector
		int Current = Queue.front();
		Queue.pop();
		Result.push_back(Current);

		//Sets 'i' to be the one of the neighbors of the point saved on 'current'
		for (int i : Adjacent[Current])
		{
			//If the neighbor has not been visited, it is set to visited and pushed into queue
			if (!Visited[i])
			{
				Visited[i] = true;
				Queue.push(i);
			}
		}
	}

	//Once all points are visited, prints out the result to the console
	std::cout << "Breadth first search:" << std::endl;
	for (int i = 0; i < Result.size(); i++)
	{
		std::cout << Points.GetID(Result[i]) << " -> ";
	}
	std::cout << "End" << std::endl << std::endl;
}

//Checks for if the map is valid
bool GraphTraversal::CheckMap()
{
	//Check variables
	bool Valid = true;
	int StartTile = 0;
	int ExitTile = 0;
	int ItemTile = 0;

	//Loops through the whole map
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			//if there is an 's' tile, add to start tile check
			if (Map[i][j] == 's')
			{
				StartTile += 1;
			}
			//if there is an 'x' tile, add to exit tile check
			else if (Map[i][j] == 'x')
			{
				ExitTile += 1;
			}
			//if there is a point tile, add to item tile check
			else if (Map[i][j] == 'a' || Map[i][j] == 'b' || Map[i][j] == 'c' || Map[i][j] == 'd' || Map[i][j] == 'e' || Map[i][j] == 'f' || Map[i][j] == 'g' || Map[i][j] == 'h' || Map[i][j] == 'i' || Map[i][j] == 'j')
			{
				ItemTile += 1;
			}
		}
	}
	
	//Below is the conditions for if the map is invalid
	//Invalid if there is more or less than one start tiles
	if (StartTile != 1)
	{
		std::cout << "Error: There is an invalid amount of Start tiles" << std::endl;
		Valid = false;
	}
	//Invalid if there is more or less than one exit tiles
	else if (ExitTile != 1)
	{
		std::cout << "Error: There is an invalid amount of Exit tiles" << std::endl;
		Valid = false;
	}
	//Invalid if there is more or less than 10 item tiles
	else if (ItemTile != 10)
	{
		std::cout << "Error: There is an invalid amount of Item tiles" << std::endl;
		Valid = false;
	}
	
	//Returns the valid check, set to true by default
    return Valid;
}

