#pragma once
#include <vector>
#include "edge.h"



class Vertex
{
public:
	Vertex();
	~Vertex();
	std::vector<Edge*> con;

};

