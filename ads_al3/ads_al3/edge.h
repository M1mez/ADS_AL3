#pragma once

#include "vertex.h"
#include <iostream>
#include <string>

class Vertex;

struct Edge
{
	int dist;	// distance
	int linienId;
	Vertex* a = nullptr;
	Vertex* b = nullptr;
};

