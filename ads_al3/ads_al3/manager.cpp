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
	Vertex *prevV = nullptr;
	Vertex *currV = nullptr;
	Edge *prevE = nullptr;
	Edge *currE = nullptr;

	int lineID = 0, dist = 0;

	path = "../../ubahn.txt";

	ifstream ifs(path.c_str());

	while (getline(ifs, line, '\n')) // ganze line einlesen
	{
		stringstream ss(line);
		getline(ss, name, ':');    // name der öffi-linie

		
#pragma region read first Station
		getline(ss, devNull, '"');
		getline(ss, station, '"'); // name der station

		if (m_stations.count(station))
		{
			prevV = m_stations[station];
			m_stations[station]->m_crossing = true;
		}
		else
		{
			m_stations[station] = prevV = new Vertex(station);
		}

		if (prevV->m_crossing) prevV->m_lineName += " ";
		prevV->m_lineName += name;
		m_endStation.push_back(prevV);
#pragma endregion 
		
		m_lineIds.push_back(name);

		while (getline(ss, devNull, ' ')) // wenn kein blankspace in der aktuellen Zeile verfügbar, Abbruch.
		{

#pragma region read station and distance
			ss >> dist;
			getline(ss, devNull, '"');
			getline(ss, station, '"'); // name der station

			if (m_stations.count(station))
			{
				currV = m_stations[station];
				currV->m_crossing = true;
			}
			else
			{
				m_stations[station] = currV = new Vertex(station);
			}
			if (currV->m_crossing) currV->m_lineName += " ";
			currV->m_lineName += name;
#pragma endregion 

			
		

			//if (ss.eof()) break;

#pragma region create new edge on previous vertex
			prevE = new Edge();
			prevE->m_target = currV;
			prevE->m_distance = dist;
			prevE->m_lineId = lineID;
			prevV->m_edges.push_back(prevE);
#pragma endregion

#pragma region create new edge on current vertex
			currE = new Edge();
			currE->m_target = currV;
			currE->m_distance = dist;
			currE->m_lineId = lineID;
			currV->m_edges.push_back(currE);
#pragma endregion

			prevV = currV; // currV ist im nächsten durchgang der alte vertex prevV

		}
		lineID++;
	}

}

void Manager::testOut()
{
	int lineID = 0;
	Edge* currE = nullptr;
	Edge* prevE = nullptr;
	Vertex* currV = nullptr;
	Vertex* prevV = nullptr;
	bool isLast = true;

	for (auto firstV : m_endStation)
	{
		currV = firstV;

		isLast = false;

		while (!isLast || (currV->m_edges.size()>1))
		{
			
			for (auto targetLineE : currV->m_edges)
			{
				if ((targetLineE->m_lineId == lineID) && (targetLineE != prevE))
				{
					currE = targetLineE;
					break;
				}
			}
			currV = currE->m_target;
			if (currV->m_edges.size() == 1) isLast = true;
			if (isLast) cout << "fehler";
			if (currV != firstV)
			{
				cout << prevV->m_stationName << " " << currE->m_distance << " " << currV->m_stationName << endl;
			}
			prevV = currV;
			currV = currE->m_target;

		}
	}
	





	//for (auto curV : m_endStation)
	//{
	//	//= m_stations["Leopoldau"];
	//	curE = curV->con[0];

	//	while (curE)
	//	{
	//		//cout << curV->m_name << " -> ";

	//		curV = curE->b;
	//		curE = (curV->con.size() == 2) ? curV->con[1] : nullptr;
	//	}
	//	if (curV->m_crossing)
	//	{
	//		cout.width(20); cout << left << curV->m_name << "  " << curV->lineName << "\n";
	//	}
	//	//cout << curV->m_name;
	//}

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
