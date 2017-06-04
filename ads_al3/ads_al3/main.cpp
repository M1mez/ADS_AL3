#include <iostream>
#include <string>
#include "manager.h"
#include "validation.h"

using namespace std;

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
	man.getQuery(startStation, endStation);

	//Find route
	try
	{
		man.findRoute(startStation, endStation);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return 0;
	}

	cout << endl;
	system("pause");
	return 0;
}