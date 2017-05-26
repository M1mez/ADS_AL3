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

	if ()

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