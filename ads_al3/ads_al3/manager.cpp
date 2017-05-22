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
	Vertex *currentV = NULL, *prevV = NULL;
	Edge *edge;
	int lineID = 1;

	path = "../../ubahn.txt";

	ifstream ifs(path.c_str());

	/*while (!ifs.eof())
	{*/
		getline(ifs, line, '\n');  // ganze line einlesen
		stringstream ss(line);
		getline(ss, name, ':');    // name der öffi-linie

		getline(ss, devNull, '"');
		getline(ss, station, '"'); // name der station


		if (m_stations.count(station))
		{
			m_stations[name]->cross = true;
		}
		else
		{
			m_stations[name] = prevV = new Vertex(name);
		}

		int dist = 0;
		
		while (ss.good()) {

			getline(ss, devNull, ' ');
			ss >> dist;
			getline(ss, devNull, '"');

			getline(ss, station, '"'); // name der station

			if (m_stations.count(station))
			{
				m_stations[station]->cross = true;
			}
			else
			{
				m_stations[station] = currentV = new Vertex(name);
			}

			edge = new Edge();
			edge->a = prevV;
			edge->b = currentV;
			edge->dist = dist;
			edge->linienId = lineID;

			prevV->con.push_back(edge);
			currentV->con.push_back(edge);

			prevV = currentV;
			cout << station;
		}
		lineID++;
	//}

}

void Manager::testOut()
{
	Edge* curE;
	Vertex* curV = m_stations["Leopoldau"];
		system("pause");
	curE = curV->con[0];
	while (curE)
	{
		cout << curV->m_name << " -> ";

		//curE = curV->con.at(1);
		if (curE) curV = curE->b;
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
