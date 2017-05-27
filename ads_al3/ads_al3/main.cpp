#include <iostream>
#include <string>
//#include <map> derzeit hier nicht verwendet
#include "manager.h"
#include "validation.h"

using namespace std;

int main (int argc, char *argv[])
{
	cout << endl << "Starting ADS_AL3..." << endl;

	string startStation, endStation;
	Manager man;
	
	//check command line parameters.
	if (!validate (argc, argv)) return 0;

	cout << "Building Network, this may take a moment..." << endl;

	//Build Data Structures
	man.readFile();
	cout << "Success!" << endl << endl;


	man.testOut(1);

	//Get Query from User
	man.getQuery (startStation, endStation);

	//Find route
	man.findRoute (startStation, endStation);
/*
	if (argc > 1)
	{
		startStation = argv[1];
		endStation = argv[2];
		cout << endl << "From " << startStation << " to " << endStation << ":" << endl << endl;
	}
	else man.testOut(0);



*/
	cout << endl;
	return 0;
}
/*
Stunden:

Sebi:
	7,5h

Johannes:
	10,5h



*/