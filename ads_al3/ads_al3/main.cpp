#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include "manager.h"
#include "validation.h"

using namespace std;

bool shallContinue();

int main (int argc, char *argv[])
{
	string startStation, endStation;
	Manager man;

	cout << endl << "Starting ADS_AL3..." << endl;

	//check command line parameters.
	if (!validate(argc, argv))
	{
		cout << endl;
		return 0;
	}

	cout << "Building Network, this may take a moment..." << endl;

	//Build Data Structures
	man.readFile((string)argv[1]);
	cout << "Success!" << endl << endl;

	while (shallContinue())
	{
		//Get Query from User
		man.getQuery (startStation, endStation);

		//Find route
		try
		{
			man.findRoute (startStation, endStation);
		}
		catch (exception &e)
		{
			cout << e.what() << endl;
			return 0;
		} 
	} 
	
	man.deleteDatastructure();
	cout << endl << "Travel safely!" << endl << endl;
	return 0;
}

bool shallContinue ()
{
	std::string input = "";

	do
	{
		std::cout << endl << "Continue to Query? (Y/N)" << endl;
		std::cin  >> input;

		cin.clear();
		cin.ignore(INT_MAX, '\n');

		transform(input.begin(), input.end(), input.begin(), ::tolower);

		if (input == "y" || input == "yes")
		{
			cout << endl;
			return true;
		}
		if (input == "n" || input == "no" )
		{
			cout << endl;
			return false;
		}
		else cout << endl << "Invalid input!" << endl << endl;		

	}	while (1);
}