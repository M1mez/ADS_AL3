#include <limits>
#include "algorithm.h"
#include "manager.h"
#include "vertex.h"
#include "edge.h"

using namespace std;

Algorithm::Algorithm (Manager *man) : manager(man)
{
}


Algorithm::~Algorithm  ()
{
}

void Algorithm::addQuery (Vertex* orig, Vertex* dest)
{
	origin      = orig;
	destination = dest;
}


//TO DO: FINISH THIS. Problem: Distance needs to be rechecked in every node, bc of line switch? Thread?
std::vector <Vertex* > Algorithm::runQuery ()
{
	std::vector <Vertex* > Neighbours;
	std::vector <Edge* >	 shortestPath;
	Vertex* currInspected;
	currLine = nullptr;

	this->initialize ();
	while(!queue.front()->isGoal)
	{
		//select currently shortest path to be inspected, return route, if Goal is reached.
		currInspected = queue.front();

		//look at all connections, check if Path is shorter and change Vertex distance and previous, if so.
		for (auto i : currInspected->m_edges)
		{
			checkPathLength (currInspected, i->m_target, i->getDistance(currLine));
		}	
	}

	return finish (queue.front());
 	cout << "succesfully ran a query. kappa." << endl;
}


void Algorithm::initialize ()
{
	for (auto i : manager->m_stations)
	{
		i->pathLenght = std::numeric_limits<int>::max();
		i->previous = nullptr;
		i->destination = false;
	}

	this->origin->pathLenght = 0;
	this->destination->isGoal = true;

	queue.push_front (origin);
}

void Algorithm::checkPathLength (Vertex* originVertex, Vertex* vertexToCheck, int newDistance)
{
	if (vertexToCheck->PathLength > newDistance)
	{
		vertexToCheck->PathLength = newDistance;
		vertexToCheck->changePrevious (originVertex);
		addToQueue (i->m_target);
	}
}

//TO DO: finish this, care for order of stations.
std::vector <Vertex* > Algorithm::finish (Vertex* reachedGoal)
{
	std::vector <Vertex* > route;
	Vertex* tempVertex = reachedGoal;
	while(tempVertex->previous != nullptr)
	{
		tempVerte
	}

	return route;
}

void Algorithm::addToQueue (Vertex* addMeToQueue)
{
	//search for element and delete it from List
	for(auto i : this->queue)
	{
		if (i == addMeToQueue) this->queue.erase(i);
	}
	//insert at correct position
	for(auto i : this->queue)
	{
		if (i->pathLenght > addMeToQueue->pathLength) this->queue.insert(i, addMeToQueue);
		else if (i == queue.end()) queue.push_back (addMeToQueue);
	}

}
