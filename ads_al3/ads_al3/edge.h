#pragma once
#include "vertex.h"
#include <iostream>
#include <string>

struct Edge
{
	double dist;	// distance
	int linienId;
	Vertex* a;
	Vertex* b;
};

