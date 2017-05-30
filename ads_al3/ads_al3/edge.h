#pragma once

#include "vertex.h"
#include <iostream>
#include <string>

class Vertex;

struct Edge
{
	Edge();
	~Edge();

	int m_distance;	// distance
	int m_lineId;		//ID of the line this edge belongs to

	Vertex* m_target = nullptr;

	//return Distance, considering 5 minutes to switch lines
	int getDistance (int currLineId)
	{	
		if (currLineId == -1 || currLineId == m_lineId) return m_distance;
		else  return (m_distance + 5);
	}
};

