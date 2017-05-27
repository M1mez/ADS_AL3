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
};

