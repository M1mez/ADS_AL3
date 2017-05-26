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
	int m_lineId;

	Vertex* m_target = nullptr;
};

