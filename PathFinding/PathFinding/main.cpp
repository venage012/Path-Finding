/**************************************************************************
<Bachelor of Software Engineering (Games Development)>
Media Design School
Auckland
New Zealand
(c) <2026> Media Design School
File Name : <main.cpp>
Description : <The main body for running the program for users>
Author : <Liam Aumareva>
Mail : <liam.aumareva@mds.ac.nz>
**************************************************************************/
#include "GraphTraversal.h"

int main()
{
	//The main program and necessary loop & input variables
	GraphTraversal PathFindingProgram;
	std::string FileName;
	bool MapProgram = false;
	int Input = 0;

	//Asks the user for the link to the txt file
	std::cout << "Please enter the link to map text file (e.g: ExampleMaps/ValidMap1.txt)" << std::endl;
	std::cin >> FileName;
	//Fail check for any non-string response
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		FileName = "Blank";
	}

	//Sets up the map and also checks if the file name is valid
	system("cls");
	MapProgram = PathFindingProgram.SetMap(FileName);

	//If the file name is invalid, the program closes
	if (!MapProgram)
	{
		std::cout << "Program closing" << std::endl;
	}

	//The main program if the file name is valid
	while (MapProgram)
	{
		//Asks the user for their input on which program to open
		//More information on these functions below
		std::cout << "Enter the desired function" << std::endl
			<< "1. Show Map" << std::endl
			<< "2. Adjacency matrix" << std::endl
			<< "3. Depth-first search" << std::endl
			<< "4. Breath-first search" << std::endl
			<< "5. Select a new map" << std::endl
			<< "6. End Program" << std::endl;
		std::cin >> Input;
		//Input fail check
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			Input = 6;
		}

		//The multiple function options for the user
		system("cls");
		//1: Displays the current map saved to the program
		if (Input == 1)
		{
			PathFindingProgram.SetMap(FileName);
		}
		//2: Displays the adjacency matrix of the current map
		else if (Input == 2)
		{
			PathFindingProgram.GenerateMatrix();
		}
		//3: Displays the depth-first search of the current map
		else if (Input == 3)
		{
			PathFindingProgram.DFS();
		}
		//4: Displays the breadth first search of the current map 
		else if (Input == 4)
		{
			PathFindingProgram.BFS();
		}
		//5: Changes the current map to a new valid map that the user specifies
		else if (Input == 5)
		{
			//Variables for the map change function
			bool Check = false;
			bool ChangeLoop = true;
			int Retry = 0;
			std::string NewFile;

			//Resets the current map to empty and starts the loop for the function
			PathFindingProgram.MapReset();
			while (ChangeLoop)
			{
				//Asks the user for the fike name to the new map
				std::cout << "Please enter a valid link to map text file (e.g: ExampleMaps/ValidMap1.txt)" << std::endl;
				std::cin >> NewFile;
				//Checks for input fails
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					NewFile = "Blank";
				}

				//Checks if the file name is valid
				system("cls");
				Check = PathFindingProgram.SetMap(NewFile);

				//If the file name is invalid, the code below plays
				if (Check == false)
				{
					//Asks the user if they wish to retry with a new link
					//This also allows users a way to exit the function if they entered by accident
					system("cls");
					std::cout << "Invalid file name entered." << std::endl
						<< "Try again? (0 = Yes, 1 = No)" << std::endl;
					std::cin >> Retry;
					//Checks for failed inputs
					if (std::cin.fail())
					{
						std::cin.clear();
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						Retry = 6;
					}

					//If the user wants the exit the map change function
					system("cls");
					if (Retry == 1)
					{
						//Adds back the map via the saved file name & break the loop
						PathFindingProgram.SetMap(FileName);
						ChangeLoop = false;
					}
				}
				//If the file name is valid, Replace the saved file name with the new one & break the loop
				else
				{
					FileName = NewFile;
					ChangeLoop = false;
				}
			}
		}
		//6: closes the program
		else if (Input == 6)
		{
			system("cls");
			MapProgram = false;
			std::cout << "Thank you for using the path finding program" << std::endl;
		}
		//If the user entered an invalid answer, it goes back to the begining of the loop
		else
		{
			std::cout << "Invalid Input" << std::endl << std::endl;
		}
	}
}
