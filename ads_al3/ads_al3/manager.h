#pragma once
#include "vertex.h"
#include <vector>
#include <string>
#include <map>

class Manager
{
private:
	std::map< std::string, Vertex* > m_stations;


public:
	Manager();
	~Manager();
	Vertex* getStation(std::string name);
	void newStation(std::string name);
	void readFile();

};

