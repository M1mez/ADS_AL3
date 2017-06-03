#include "manager.h"
#include <fstream>
#include <sstream>

#define INITSTRLENGTH 20
using namespace std;

Manager::Manager()
{
	alg = new Algorithm(this);
}

Manager::~Manager()
{
	delete alg;
}

//TO DO: secure input and validate station names.
void Manager::getQuery (std::string &start, std::string &end)
{
	bool failInput = false;
	do
	{
		cout << "Please enter your search query!" << endl;
		cout << "+-----------------------------+" << endl << endl;
		cout << "Origin station: ";
		cin >> start;
		cout << endl << "Destination station: ";
		cin >> end;
		cout << endl;
	} while (start == end);
	
}

//Not tested, not finished
void Manager::findRoute (std::string &start, std::string &end)
{
	std::vector <Edge* > route;
	alg->addQuery (m_stations[start], m_stations[end]);
	route = alg->runQuery ();

	printRoute(route);
	alg->reset();
}

void Manager::readFile()
{
	string tmp, line, name, station, path, devNull;
	Vertex *prevV = nullptr;
	Vertex *currV = nullptr;
	Edge *prevE = nullptr;
	Edge *currE = nullptr;
	int longestStrLength = INITSTRLENGTH, tmpStrLength;
	int lineID = 0, dist = 0;

	path = "../../ubahnstrassenbahn.txt";

	ifstream ifs(path.c_str());

	while (getline(ifs, line, '\n')) // ganze line einlesen
	{
		stringstream ss(line);
		getline(ss, name, ':');		 // name of the subway-line

#pragma region read first Station
		getline(ss, devNull, '"');
		getline(ss, station, '"'); // name der station

		prevV = newStation(station);

		if (prevV->m_crossing) prevV->m_lineList += " ";
		prevV->m_lineList += name;
#pragma endregion 
		
		m_startStations.push_back(prevV);
		
		m_lineNames.push_back(name);

		while (getline(ss, devNull, ' ')) // wenn kein blankspace in der aktuellen Zeile verfügbar, Abbruch.
		{

#pragma region read station and distance
			ss >> dist;
			getline(ss, devNull, '"');
			getline(ss, station, '"'); // name der station

			currV = newStation(station);

			if (currV->m_crossing) currV->m_lineList += " ";
			currV->m_lineList += name;
#pragma endregion 

#pragma region create new edge on previous vertex
			prevE = new Edge();
			prevE->m_target = currV;
			prevE->m_distance = dist;
			prevE->m_lineId = lineID;
			prevV->m_edges.push_back(prevE);
#pragma endregion

#pragma region create new edge on current vertex
			currE = new Edge();
			currE->m_target = prevV;
			currE->m_distance = dist;
			currE->m_lineId = lineID;
			currV->m_edges.push_back(currE);
#pragma endregion

			prevV = currV; // currV ist im nächsten durchgang der alte vertex prevV

			tmpStrLength = station.length();
			if (longestStrLength < tmpStrLength) longestStrLength = tmpStrLength;

		}
		m_lineMaxStringLength.push_back(longestStrLength);
		longestStrLength = INITSTRLENGTH;
		m_endStations.push_back(prevV);
		lineID++;
	}

}

void Manager::printRoute(vector<Edge*> &route)
{
	bool isAtStartStation = true;
	int	 currLine = 0;

	//Print start station
	cout << route.front()->m_target->previous->m_target->m_stationName;
	for (auto tempE : route)
	{
		if (isAtStartStation)
		{
			isAtStartStation = false;
		}
		else
		{
			if (currLine != tempE->m_lineId)
			{
				cout << endl << endl << "Umsteigen von Linie " << m_lineNames.at(currLine) << " auf Linie " << m_lineNames.at(tempE->m_lineId) << "." << endl << endl;
				cout << tempE->m_target->previous->m_target->m_stationName;
			}
		}
		cout << " -> " << endl << tempE->m_target->m_stationName;
		currLine = tempE->m_lineId;
	}

	cout << endl;
}

//void Manager::testOut(bool dir)
//{
//	vector< Vertex* > &stationList = dir ? m_startStations : m_endStations;
//	int lineID = 0, i = 0;
//	int m_edgeSize = 2;
//	Edge* nextE = nullptr;
//	Vertex* nextV = nullptr;
//	Vertex* prevV = nullptr;
//	bool notFirst = true;
//
//	for (auto firstV : stationList)
//	{
//		cout << "Linie " << m_lineNames.at(lineID) << endl << "~~~~~~~~~~~~" << endl;
//		nextV = firstV;
//		while (true)
//		{
//			nextE = nextV->findNextE(prevV, lineID);	 // find next Edge	
//			prevV = nextV;								 // set previous Vertex to distinguish where we came from
//			if (nextE == nullptr) break;
//			nextV = nextE->m_target;					 // set next Vertex
//			
//			cout.width(m_lineMaxStringLength.at(lineID)); cout << left << prevV->m_stationName << " " << nextE->m_distance << " min ->   ";
//			cout.width(m_lineMaxStringLength.at(lineID)); cout << nextV->m_stationName << endl;
//			
//			if (nextV->m_edges.size() == 1) break;
//		}
//		prevV = nullptr;
//		lineID++;
//		cout << "\n\n";
//	}
//}


Vertex* Manager::newStation(std::string name)
{
	Vertex* v;
	if (m_stations.count(name))
	{
		v = m_stations[name];
		v->m_crossing = true;
	}
	else
	{
		m_stations[name] = v = new Vertex(name);
	}

	return v;
}
