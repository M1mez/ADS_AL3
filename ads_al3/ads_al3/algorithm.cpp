#include <limits>
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
	destination->isGoal = true;
	queue.push_front(origin);
}

//TO DO: FINISH THIS. Problem: Distance needs to be rechecked in every node, bc of line switch? Thread?
std::vector <Vertex* > Algorithm::runQuery ()
{
	//std::vector <Vertex* > Neighbours; obsolete?
	std::vector <Edge* > shortestPath;
	Vertex* currInspected;
	int currLine;

	//this->initialize (); in diverse Methoden verteilt (Constructor von Vertex, addQuery)
	while(!queue.front()->isGoal)
	{
		//select currently shortest path to be inspected, return route, if Goal is reached.
		currInspected = queue.front();
		if (find(visitedStations.begin(), visitedStations.end(), currInspected) != visitedStations.end())
		currLine = currInspected->previous->m_lineId;
		//look at all connections, check if Path is shorter and change Vertex distance and previous, if so.
		for (auto i : currInspected->m_edges)
		{
			checkPathLength (i, i->m_target, i->getDistance(currLine));
		}
		// currLine = 
	}

	return finish (queue.front());
 	cout << "succesfully ran a query. kappa." << endl;
}

/*
void Algorithm::initialize ()
{
	for (auto i = manager->m_stations.begin(); i != manager->m_stations.end(); i++)
	{
		i->second->pathLength = INT_MAX;
		i->second->previous = nullptr;			// Hab das in den Constructor von Vertex gepackt, wenns eh für alle passiert
		i->second->isGoal = false;
	}

	this->origin->pathLength = 0;
	this->destination->isGoal = true;    // Hab das in addQuery gepackt, initialize muss ohnehin danach aufgerufen werden

	queue.push_front (origin);
}*/

void Algorithm::checkPathLength(Edge* previousEdge, Vertex* vertexToCheck, int newDistance)
{
	if (vertexToCheck->pathLength > newDistance)
	{
		vertexToCheck->pathLength = newDistance;
		vertexToCheck->changePrevious (previousEdge);
		addToQueue (vertexToCheck);
	}
}

//TODO: finish this, care for order of stations.
//std::vector <Vertex* > Algorithm::finish (Vertex* reachedGoal)
//{
//	std::vector <Vertex* > route;
//	Vertex* tempVertex = reachedGoal;
//	while(tempVertex->previous != nullptr)
//	{
//		tempVerte
//	}
//
//
//	return route;
//}

void Algorithm::addToQueue (Vertex* addMeToQueue)
{
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
