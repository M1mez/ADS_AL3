#include "vertex.h"

using namespace std;

Vertex::Vertex(string name) : m_stationName(name)
{
	m_crossing = false;
	m_lineList = "";
}


Vertex::~Vertex()
{
}

int Vertex::findBest(Vertex* dest)
{
	int best = INT_MAX;
	int nextInt;

	for (auto e : m_edges)
	{
		nextInt = e->m_target->findBest(dest);
		best = best < nextInt ? best : nextInt;
	}



	return best;
}

Edge* Vertex::findNextE(Vertex* prevV, int line)
{
	Edge *nextE = nullptr;

	for (auto tempE : m_edges)
	{
		if ((tempE->m_target != prevV) && (tempE->m_lineId == line))
		{
			nextE = tempE;
			break;
		}
	}
	return nextE;
}


void Vertex::changePrevious (Vertex* previousStation);
{
	for (auto iterEdge : m_edges)
	{
		if(iterEdge->target == previousStation) this->previous = iterEdge;
	}
}

//NEEDS TO BE TESTED
std::vector <Vertex*> getNeighbours ()
{
	bool vertexIsNew = true;
	std::vector <Vertex*> neighbours;
	Vertex* tempVertex = new Vertex ();

	for (auto tempE : m_edges)
	{
		tempVertex = tempE->m_target;

		for (auto tempV : neighbours)
		{
			if(tempVertex == tempV) vertexIsNew = false;
		}

		vertexIsNew ? neighbours.push_back (tempVertex) : vertexIsNew = true;
	}

	return neighbours;
}