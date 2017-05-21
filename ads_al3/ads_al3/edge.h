#pragma once
#include "vertex.h"

struct Edge
{
	double dist;	// distance
	int linienId;
	Vertex* a;
	Vertex* b;
};

