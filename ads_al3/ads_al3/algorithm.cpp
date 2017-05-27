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


//TO DO: FINISH THIS
void Algorithm::runQuery ()
{
	std::vector <Vertex* > Neighbours;
	Vertex* currInspected;

	this->initialize ();
	while(true)
	{
		currInspected = queue.front();

		Neighbours = currInspected->getNeighbours ();
		for (auto i : Neighbours)
		{

		}
		


	}





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
