#include "manager.h"
#include <fstream>
#include <sstream>

using namespace std;

Manager::Manager()
{
}


Manager::~Manager()
{
}


void Manager::readFile()
{
	string tmp, line, name, station, path, devNull;
	int a, b;
	a = b = 0;

	path = "../../ubahn.txt";

	ifstream ifs(path.c_str());


	getline(ifs, line, '\n');
	stringstream ss(line);

	getline(ss, name, ':');
	getline(ss, devNull, '"');
	getline(ss, station, '"');

		if (m_stations.count(station))
		{

		}
		else
		{
			m_stations[name] = new Vertex(name);
		}


	if (ifs.good()) {
		
		m_labString += (tmp + '\n');
		m_height++;

		m_width = tmp.size();

		while (!ifs.eof()) {
			getline(ifs, tmp, '\n');
			if (tmp.size() == m_width)
			{
				m_labString += (tmp + '\n');
				m_height++;
			}
		}
		m_width++;
	}

}

Vertex* Manager::getStation(std::string name)
{
	return m_stations[name];
}

void Manager::newStation(std::string name)
{
	if (m_stations.count(name))
	{

	}
	else
	{
		m_stations[name] = new Vertex(name);
	}
}
