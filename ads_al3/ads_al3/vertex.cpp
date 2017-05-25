#include "vertex.h"

using namespace std;

Vertex::Vertex(string name) : m_stationName(name)
{
	m_crossing = false;
	m_lineName = "";
}


Vertex::~Vertex()
{
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