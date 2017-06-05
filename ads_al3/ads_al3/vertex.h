#pragma once

#include <vector>
#include <string>
#include "edge.h"

class Edge;

class Vertex
{
public:
	Vertex (std::string name);
	~Vertex ();

	//All Edges, connected to the Station
	std::vector<Edge*> m_edges;

	//used in algorithm.h
	Edge* previous;
	int pathLength;

	//Name of the station
	std::string m_stationName;

	//Set 'Edge* previous' to Edge pointing at 'originVertex'.
	void changePrevious (Vertex* originVertex);
	
};

