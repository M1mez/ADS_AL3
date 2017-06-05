#include "manager.h"
#include "validation.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <string>
#include <climits>
#include <cctype>

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
		getline (cin, start);

		cout << endl << "Destination station: ";
		getline (cin, end);

		cout << endl;

		// Ignore upper-/lowercase
		for (int i = 0 ; i < (int) start.length(); i++)
		{
			if (isspace(start[i - 1])) start[i] = toupper(start[i]);
			else start[i] = tolower(start[i]);
		}

		for (int i = 0 ; i < (int) end.length(); i++)
		{
			if (isspace(end[i - 1])) end[i] = toupper(end[i]);
			else end[i] = tolower(end[i]);
		}
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
	int longestStrLength = INITSTRLENGTH;
	int lineID = 0, dist = 0;


	ifstream ifs(path.c_str());

	while (getline(ifs, line, '\n')) // read total information of a network line
	{
		stringstream ss(line);
		getline(ss, name, ':');		 // name of thenetwork line

	// read first Station
		getline(ss, devNull, '"');
		getline(ss, station, '"'); // name of first station

		prevV = newStation(station);

		m_lineNames.push_back(name);

		while (getline(ss, devNull, ' ')) // reads until the end of the line that was read earlier
		{

	// read station and distance
			ss >> dist;
			getline(ss, devNull, '"');
			getline(ss, station, '"'); // name of the station

			currV = newStation(station);

			
	// create new edge on previous vertex
			prevE = new Edge(dist, lineID, currV);
			prevV->m_edges.push_back(prevE);
			
	// create new edge on current vertex
			currE = new Edge(dist, lineID, prevV);
			currV->m_edges.push_back(currE);

			prevV = currV; // currV is now prevV in next loop.
		}
		lineID++;
	}

}

void Manager::printRoute(vector<Edge*> &route) const
{
	bool isAtStartStation = true;
	int	 currLine = 0;
	int longestStationName = 0;
	int totalPathLength = 0;

	//if route is empty, no path was found.
	if(route.empty())
	{
		cout << "Error! No connection between the stations was found!" << endl;
		return;
	}

	//length of Startstation name.
	longestStationName = route.front()->m_target->previous->m_target->m_stationName.length();

	//get longestStationName and total pathlength.
	for (auto tempE : route)
	{
		totalPathLength += tempE->m_distance;
		if( (int) tempE->m_target->m_stationName.length() > longestStationName)
		{
			longestStationName = ( tempE->m_target->m_stationName.length() );
		}
	}
	//Buffer
	longestStationName += 5;

	for (auto tempE : route)
	{
		//check if line needs to be changed at output message, if so.
		if (isAtStartStation)
		{
			isAtStartStation = false;

			//Print start station

			cout << "Take Line " << m_lineNames.at(tempE->m_lineId) << endl << endl;
			cout << route.front()->m_target->previous->m_target->m_stationName;
		}
		else
		{
			if (currLine != tempE->m_lineId)
			{
				cout << endl << endl << "Umsteigen von Linie " << m_lineNames.at(currLine) << " auf Linie " << m_lineNames.at(tempE->m_lineId) << "." << endl << endl;
				cout << tempE->m_target->previous->m_target->m_stationName;
			}
		}
		//Output of next station on the route. length of longest name minus length of current station name as buffer.
		cout << setw(longestStationName - tempE->m_target->previous->m_target->m_stationName.length());
		cout << " -> " << tempE->m_distance << " min" << endl << tempE->m_target->m_stationName;
		currLine = tempE->m_lineId;
	}

	cout << endl << endl << "Total travel time: " << totalPathLength << " minutes." << endl;
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

void Manager::deleteDatastructure()
{
	//Delete all Stations. Edges connected are deleted in Vertex destructor.
	for(auto i = m_stations.begin(); i != m_stations.end(); i++)
	{
		delete (i->second);
	}
}
