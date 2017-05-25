#pragma once

#include "vertex.h"
#include <vector>
#include <string>
#include <map>

class Manager
{
private:
	std::map< std::string, Vertex* > m_stations;
	std::vector< Vertex* > m_startStations;
	std::vector< Vertex* > m_endStations;
	std::vector<std::string> m_lineNames;
	std::vector<int> m_lineMaxStringLength;
	void readFile();

public:
	Manager();
	~Manager();

	Vertex* newStation(std::string name);
	void printRoute(std::vector<Vertex*> &route);


	void testOut(bool dir);

};

