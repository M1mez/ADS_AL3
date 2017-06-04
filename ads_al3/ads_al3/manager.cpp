#include "manager.h"
#include "validation.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>

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
	do
	{
		cout << "Please enter your search query!" << endl;
		cout << "+-----------------------------+" << endl << endl;
		cout << "Origin station: ";
		cin >> start;
		cout << endl << "Destination station: ";
		cin >> end;
		cout << endl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');

		// Ignore upper-/lowercase
		transform(start.begin(), start.end(), start.begin(), ::tolower);
		transform(end.begin(), end.end(), end.begin(), ::tolower);
		start[0] = toupper(start[0]);
		end[0] = toupper(end[0]);

	} while (validateUserQuery(start, end, m_stations));
	
}

//Not tested, not finished
void Manager::findRoute (std::string &start, std::string &end)
{
	std::vector <Edge* > route;
	route = alg->runQuery (m_stations[start], m_stations[end]);

	printRoute(route);
	alg->reset();
}

void Manager::readFile(std::string path)
{
	string tmp, line, name, station, devNull;
	Vertex *prevV = nullptr;
	Vertex *currV = nullptr;
	Edge *prevE = nullptr;
	Edge *currE = nullptr;
	int longestStrLength = INITSTRLENGTH, tmpStrLength;
	int lineID = 0, dist = 0;


	ifstream ifs(path.c_str());

	while (getline(ifs, line, '\n')) // ganze line einlesen
	{
		stringstream ss(line);
		getline(ss, name, ':');		 // name of the subway-line

	// read first Station
		getline(ss, devNull, '"');
		getline(ss, station, '"'); // name der station

		prevV = newStation(station);


		
		m_lineNames.push_back(name);

		while (getline(ss, devNull, ' ')) // wenn kein blankspace in der aktuellen Zeile verfügbar, Abbruch.
		{

	// read station and distance
			ss >> dist;
			getline(ss, devNull, '"');
			getline(ss, station, '"'); // name der station

			currV = newStation(station);

			
	// create new edge on previous vertex
			prevE = new Edge(dist, lineID, currV);
			prevV->m_edges.push_back(prevE);
			
	// create new edge on current vertex
			currE = new Edge(dist, lineID, prevV);
			currV->m_edges.push_back(currE);

			prevV = currV; // currV ist im nächsten durchgang der alte vertex prevV
		}
		lineID++;
	}

}

void Manager::printRoute(vector<Edge*> &route) const
{
	bool isAtStartStation = true;
	int	 currLine = 0;

	for (auto tempE : route)
	{
		//check if line needs to be changed at output message, if so.
		if (isAtStartStation)
		{
			isAtStartStation = false;

			//Print start station
			cout << route.front()->m_target->previous->m_target->m_stationName;
			cout << ". Take Line " << m_lineNames.at(tempE->m_lineId) << " ";
		}
		else
		{
			if (currLine != tempE->m_lineId)
			{
				cout << endl << endl << "Umsteigen von Linie " << m_lineNames.at(currLine) << " auf Linie " << m_lineNames.at(tempE->m_lineId) << "." << endl << endl;
				cout << tempE->m_target->previous->m_target->m_stationName;
			}
		}
		//Output of next station on the route.
		cout << " -> " << endl << tempE->m_target->m_stationName;
		currLine = tempE->m_lineId;
	}

	cout << endl;
}

Vertex* Manager::newStation(std::string name)
{
	Vertex* v;
	if (m_stations.count(name))
	{
		v = m_stations[name];
	}
	else
	{
		m_stations[name] = v = new Vertex(name);
	}

	return v;
}
