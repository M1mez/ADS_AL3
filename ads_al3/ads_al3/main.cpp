#include <iostream>
#include "manager.h"

using namespace std;

int main(int argc, char *argv[])
{
	string startStation, endStation;
	Manager man;

	if (argc > 1)
	{
		startStation = argv[1];
		endStation = argv[2];
		cout << endl << "From " << startStation << " to " << endStation << ":" << endl << endl;
	}
	//else man.testOut(0);


	cin.get();

	return 0;
}
/*
Stunden:

Sebi:


Johannes:



*/