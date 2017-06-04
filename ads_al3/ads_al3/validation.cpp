#include <iostream>
#include <string>
#include <fstream>
#include "validation.h"

using namespace std;

int validate (int &argc, char** argv)
{
	//Only 1 argument
	if (argc != 2)
	{
		cout << "Error! Invalid number of command line arguments!" << endl << endl;
		printHelp ();
		return 0;
	}
	//file existence check
	else if (!fexists (argv[1]))
	{
		cout << "Error! Inexisting file!" << endl << endl;
		return 0;
	}

	else
	{
		cout << "Network File was found successfully!" << endl;
	}
	return 1;
}


bool fexists (const string &filename)
{	
 	ifstream ifile (filename.c_str ());
 	return (bool)ifile;
}

void printHelp ()
{
	cout << "------ADS_AL3 HELP PAGE------" << endl << endl;
	cout << "<1> Syntax:" << endl;
	cout << "ads_al3 <networkFile>" << endl << endl;
	cout << "<2> networkFile:" << endl;
	cout << "Path of the file containing the Network data." << endl << endl;
}

bool validateUserQuery(string start, string end, const map< string, Vertex* > &m_stations)
{
	bool invalidStations = false;


	if (m_stations.count(start) == 0 || start.empty())
	{
		invalidStations = true;
		cout  << "Origin does NOT exist!"<< endl << endl;
	}
	if (m_stations.count(end) == 0 || end.empty())
	{
		invalidStations = true;
		cout  << "Destination does NOT exist!"<< endl << endl;
	}
	if (start.compare(end) == 0)
	{
		invalidStations = true;
		cout <<  "Origin and Destination must NOT be the same!" << endl << endl;
	}

	return invalidStations;
}