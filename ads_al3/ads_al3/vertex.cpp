#include <climits>
#include "vertex.h"

using namespace std;

Vertex::Vertex(string name) : m_stationName(name)
{
	m_crossing = false;
	m_lineList = "";
	pathLength = INT_MAX;
	previous = nullptr;
}


Vertex::~Vertex()
{
}

void Vertex::changePrevious(Vertex* originVertex)
{
	//cout << endl << m_stationName << " -> CURRENT " << endl;
	//cout << originVertex->m_stationName << " -> SUCHE " << endl;
	for (auto iterEdge : m_edges)
	{
		//cout << iterEdge->m_target->m_stationName << " -> EDGE " << endl;

		if(iterEdge->m_target == originVertex)
		{
		 	this->previous = iterEdge;
		 	return;
		}
	}
	throw runtime_error("Error in Algorithm! Oneway connection between two stations?");
}


/*
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
*/