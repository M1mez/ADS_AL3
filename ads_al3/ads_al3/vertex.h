#pragma once

#include <vector>
#include <string>
#include "edge.h"

//#define INT_MAX 100 ist schon ein Makro, eben max von INT

struct Edge;


class Vertex
{
public:
	Vertex (std::string name);
	~Vertex ();

	//Edges, connected to the Station
	std::vector<Edge*> m_edges;

	//optimizations
	bool m_crossing;
	bool m_isEndStation;

	//used in algorithm.h
	Edge* previous;
	int 	pathLength;
	bool	isGoal;

	int findBest(Vertex* dest);
	
	//Name of the station,
	//and string containing all lines
	//who use this station (printed as info/formatting  only)
	std::string m_stationName;
	std::string m_lineList;

	void changePrevious (Edge* previousEdge);

	Edge* findNextE(Vertex* prevV, int line);
};

