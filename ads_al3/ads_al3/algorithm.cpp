#include <climits>
#include <algorithm>
#include "algorithm.h"
#include "manager.h"
#include "vertex.h"
#include "edge.h"

using namespace std;

Algorithm::Algorithm (Manager *man) : manager(man){}
Algorithm::~Algorithm  (){}

void Algorithm::initializeQuery (Vertex* orig, Vertex* dest)
{
	origin      = orig;
	destination = dest;

	origin->pathLength = 0;
	//set dummy previous, to recognize starting station
	origin->previous = new Edge (0, -1, nullptr);
	queue.push_front(origin);
}

std::vector <Edge* > Algorithm::runQuery (Vertex* orig, Vertex* dest)
{
	//route will be saved here
	std::vector <Edge* > shortestPath;

	//initialize the query.
	this->initializeQuery (orig, dest);

	//Station currently inspected for connections
	Vertex* currInspected;

	while(queue.front() != this->destination)
	{

		//select currently shortest path to be inspected, return route, if Goal is reached.

		//if empty, there is no connection between origin and destination, so an empty path is returned.
		//Check for this before starting to print.
		if(queue.empty())
		{
			return shortestPath;
		}
		else
		{
			currInspected = queue.front();
		}	

		//look at all connections, check if Path is shorter and change Vertex distance and previous, if so.
		for (auto i : currInspected->m_edges)
		{
			checkPathLength (currInspected, i->m_target, i->getDistance(currInspected->previous->m_lineId)+currInspected->pathLength);
		}

		//Remember stations already checked and remove them from the queue.
		visitedStations.push_back(queue.front());
		queue.pop_front();

	}
	shortestPath = finish (queue.front());
	queue.clear();
	visitedStations.clear();
	return shortestPath;
}

void Algorithm::reset ()
{
	//delete dummy Edge, created in Algorithm::initializeQuery.
	delete origin->previous;

	for (auto i = manager->m_stations.begin(); i != manager->m_stations.end(); i++)
	{
		i->second->pathLength = INT_MAX;
		i->second->previous = nullptr;
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

std::vector <Edge* > Algorithm::finish (Vertex* reachedGoal) const
{
	vector <Edge* > route;
	Edge* currE = reachedGoal->previous;
	Vertex* currV = reachedGoal;

	while (currE->m_target != origin)
	{
		route.insert(route.begin(), turnPrevious(currV));

		currV = currE->m_target;
		currE = currE->m_target->previous;
	}
	route.insert(route.begin(), turnPrevious(currV));

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
		if (*pos == addMeToQueue)
		{
			queue.remove(*pos);
			break;
		}
		pos++;
	}
	//insert at correct position
	pos = queue.begin();

	while (pos != queue.end())
	{
		if ((*pos)->pathLength > addMeToQueue->pathLength)
		{
			queue.insert(pos, addMeToQueue);
			break;
		}
		pos++;
		if (pos == queue.end()) queue.push_back (addMeToQueue);
	}

}

Edge* Algorithm::turnPrevious(Vertex* originVertex) const
{
	Vertex* target = originVertex->previous->m_target;
	for (auto iterEdge : target->m_edges)
	{
		if (iterEdge->m_target == originVertex)
		{
			return iterEdge;
		}
	}
	throw runtime_error("Error in Algorithm! Oneway connection between two stations?");
}