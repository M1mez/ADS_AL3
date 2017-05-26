#pragma once

#include <vector>
#include <string>
#include "edge.h"

struct Edge;

class Vertex
{
public:
	Vertex (std::string name);
	~Vertex ();

	std::vector<Edge*> m_edges;
	bool m_crossing;
	bool m_isEndStation;
	Edge* previous;
	int pathLength;

	int findBest(Vertex* dest);
	
	std::string m_stationName;
	std::string m_lineList;

	Edge* findNextE(Vertex* prevV, int line);
};

