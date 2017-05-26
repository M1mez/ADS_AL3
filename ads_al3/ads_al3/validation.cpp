#include <iostream>
#include <string>
#include <fstream>
#include "validation.h"

int validate (int &argc, char** argv)
{
	//Only 1 argument
	if (argc != 2)
	{
		std::cout << "Error! Invalid number of command line arguments!" << std::endl << std::endl;
		printHelp ();
		return 0;
	}
	//file existance check
	else if (!fexists (argv[1]))
	{
		std::cout << "Error! Inexisting file!" << std::endl << std::endl;
		return 0;
	}

	else
	{
		std::cout << "Network File was found successfully!" << std::endl;
	}
	return 1;
}


bool fexists (const std::string &filename)
{	
 	std::ifstream ifile (filename.c_str ());
 	return (bool)ifile;
}

void printHelp ()
{
	std::cout << "------ADS_AL3 HELP PAGE------" << std::endl << std::endl;
	std::cout << "<1> Syntax:" << std::endl;
	std::cout << "ads_al3 <networkFile>" << std::endl << std::endl;
	std::cout << "<2> networkFile:" << std::endl;
	std::cout << "Path of the file containing the Network data." << std::endl << std::endl;
}