#pragma once

#include "algorithm.h"
#include "vertex.h"
#include <vector>
#include <string>
#include <map>

#define INITSTRLENGTH 20

class Algorithm;

class Manager
{
	friend class Algorithm;

private:
	//Object as Interface for the Algorithm
	Algorithm *alg;

	//Stores all stations. Find by name.
	std::map< std::string, Vertex* > m_stations;

	// all linenames, index is ID of line
	std::vector<std::string> m_lineNames;
 
	//Creates new station in the data structure.
	Vertex* newStation (std::string name);
	
	//prints shortest route
	void printRoute (std::vector<Edge*> &route) const;

public:
	Manager();
	~Manager();

	//parse input file to Datastructure
	void readFile (std::string path);

	//get query from user
	void getQuery (std::string &start, std::string &end);

	//find fastest route through network.
	void findRoute (std::string &start, std::string &end);
};

