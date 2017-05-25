#pragma once

#include "vertex.h"
#include <vector>
#include <string>
#include <map>

class Manager
{
private:
	std::map< std::string, Vertex* > m_stations;
	std::vector< Vertex* > m_endStation;
	std::map< Vertex*, std::string > m_stationLine;
	//std::map< string, int> m_stationIndex;

public:
	Manager();
	~Manager();
	Vertex* getStation(std::string name);
	void newStation(std::string name);
	void readFile();

	std::vector<std::string> m_lineIds;

	void testOut();

};

