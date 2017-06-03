#include <climits>
#include <algorithm>
#include "algorithm.h"
#include "manager.h"
#include "vertex.h"
#include "edge.h"

using namespace std;

Algorithm::Algorithm (Manager *man) : manager(man){}
Algorithm::~Algorithm  (){}

void Algorithm::addQuery (Vertex* orig, Vertex* dest)
{
	origin      = orig;
	destination = dest;

	origin->pathLength = 0;
	//set previous to -1
	origin->previous = new Edge (0, -1, nullptr);
	queue.push_front(origin);
}

//TO DO: FINISH THIS. Problem: Distance needs to be rechecked in every node, bc of line switch? Thread?
std::vector <Vertex* > Algorithm::runQuery ()
{
	std::vector <Edge* > shortestPath;
	Vertex* currInspected;

	
	while(queue.front() == this->destination)
	{
		//select currently shortest path to be inspected, return route, if Goal is reached.
		currInspected = queue.front();

	//	if (find(visitedStations.begin(), visitedStations.end(), currInspected) != visitedStations.end())
		//look at all connections, check if Path is shorter and change Vertex distance and previous, if so.
		for (auto i : currInspected->m_edges)
		{
			checkPathLength (currInspected, i->m_target, i->getDistance(currInspected->previous->m_lineId));
		}
		
		visitedStations.push_back(queue.front());
		queue.pop_front();
	}

	cout << "succesfully ran a query. kappa." << endl;
	return finish (queue.front());
}

void Algorithm::reset ()
{
	for (auto i = manager->m_stations.begin(); i != manager->m_stations.end(); i++)
	{
		i->second->pathLength = INT_MAX;
		i->second->previous = nullptr;
		i->second->isGoal = false;
	}

}

void Algorithm::checkPathLength(Vertex* originVertex, Vertex* vertexToCheck, int newDistance)
{
	if (vertexToCheck->pathLength > newDistance)
	{
		vertexToCheck->pathLength = newDistance;
		vertexToCheck->changePrevious (originVertex);
		addToQueue (vertexToCheck);
	}
}

//TODO: finish this, care for order of stations.
std::vector <Vertex* > Algorithm::finish (Vertex* reachedGoal)
{
	vector <Vertex* > route;
	Vertex* currV = reachedGoal;

	while (currV != origin)
	{
		route.insert(route.begin(), currV);
		currV = currV->previous;
	}
	route.insert(route.begin(), currV);

	return route;
}

void Algorithm::addToQueue (Vertex* addMeToQueue)
{
	for(auto i : visitedStations)
	{
		if (i == addMeToQueue) return; 
	}

	list <Vertex* >::iterator pos;
	//search for element and delete it from List
	pos = queue.begin();

	while(pos != queue.end())
	{
		if (*pos == addMeToQueue) queue.remove(*pos); 
		pos++;
	}
	//insert at correct position
	pos = queue.begin();

	while (pos != queue.end())
	{
		if ((*pos)->pathLength > addMeToQueue->pathLength) queue.insert(pos, addMeToQueue);
		else if (pos == queue.end()) queue.push_back (addMeToQueue);
		pos++;
	}

}
