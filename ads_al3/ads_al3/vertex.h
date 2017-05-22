#pragma once
#include <vector>
#include "edge.h"

struct Edge;

class Vertex
{
public:
	Vertex(std::string name);
	~Vertex();
	std::vector<Edge*> con;
	bool cross;
	std::string m_name;
};

