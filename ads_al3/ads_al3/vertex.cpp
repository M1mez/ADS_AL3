#include "vertex.h"

using namespace std;

Vertex::Vertex(string name) : m_stationName(name)
{
	m_crossing = false;
	m_lineName = "";
}


Vertex::~Vertex()
{
}
