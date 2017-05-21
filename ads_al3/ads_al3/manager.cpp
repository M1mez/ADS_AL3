#include "manager.h"



Manager::Manager()
{
}


Manager::~Manager()
{
}


void Manager::readFile()
{

}

Vertex* Manager::getStation(std::string name)
{
	return m_stations[name];
}

void Manager::newStation(std::string name)
{
	m_stations[name] = new Vertex(name);
}
