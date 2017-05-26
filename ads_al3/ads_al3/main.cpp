#include <iostream>
#include <string>
//#include <map> derzeit hier nicht verwendet
#include "manager.h"
#include "validation.h"

using namespace std;

int main (int argc, char *argv[])
{
	string startStation, endStation;

		cout << endl << "Starting ADS_AL3..." << endl;
		//check command line parameters.
		if (!validate(argc, argv)) return 0;

		cout << "Building Network, this may take a moment..." << endl;
	

	Manager man;
	man.testOut(1);
	//User Eingabe abfragen

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
	4,5h

Johannes:
	10,5h



*/