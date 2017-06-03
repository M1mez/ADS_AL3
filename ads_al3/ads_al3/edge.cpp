#include "edge.h"



Edge::Edge()
{
}

Edge::Edge(int distance, int lineId, Vertex* target)
{
	m_distance = distance;
	m_lineId   = lineId;
	m_target   = target;
}


Edge::~Edge()
{
}


int Edge::getDistance (int currLineId) const
{	
	if (currLineId == -1 || currLineId == m_lineId) return m_distance;
	else  return (m_distance + 5);
}