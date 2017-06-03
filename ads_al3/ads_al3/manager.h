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
	//Stores all stations. Find by name.
	std::map< std::string, Vertex* > m_stations;

	std::vector< Vertex* > m_startStations;
	std::vector< Vertex* > m_endStations;

	std::vector<std::string> m_lineNames;
	std::vector<int> m_lineMaxStringLength;

 
	//Creates new station in the data structure.
	Vertex* newStation (std::string name);

	//Object as Interface for the Algorithm
	Algorithm *alg;

public:
	Manager();
	~Manager();

	//parse input file to Datastructure
	void readFile ();

	void printRoute (std::vector<Edge*> &route) const;

	//get query from user
	void getQuery (std::string &start, std::string &end);
	//find fastest route through network.
	void findRoute (std::string &start, std::string &end);
	

	void testOut (bool dir);

};

