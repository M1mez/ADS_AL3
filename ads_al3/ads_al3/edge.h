#pragma once

#include "vertex.h"
#include <iostream>
#include <string>

class Vertex;

struct Edge
{
	Edge();
	Edge(int distance, int lineId, Vertex* target);
	~Edge();

	int m_distance;	// distance
	int m_lineId;		//ID of the line this edge belongs to

	Vertex* m_target = nullptr;

	//return Distance, considering 5 minutes to switch lines.
	//lineId is -1 on starting Vertex->previous.
	int getDistance (int currLineId) const;
};

