#include <climits>
#include "vertex.h"

using namespace std;

Vertex::Vertex(string name) : m_stationName(name)
{
	pathLength = INT_MAX;
	previous = nullptr;
}

Vertex::~Vertex()
{
	for (auto it = m_edges.begin(); it != m_edges.end(); ++it)
	{
		delete (*it);
	}
	m_edges.clear();
}

void Vertex::changePrevious(Vertex* originVertex)
{
	for (auto iterEdge : m_edges)
	{
		if(iterEdge->m_target == originVertex)
		{
		 	this->previous = iterEdge;
		 	return;
		}
	}
	throw runtime_error("Error in Algorithm! Oneway connection between two stations?");
}