#pragma once
#include <vector>
#include <forward_list>
#include "manager.h"
#include "vertex.h"

class Manager;

class Algorithm
{
private:
	//Connection to manager. Used to grab data from there.
	Manager* manager;

	//Query Question
	Vertex* origin;
	Vertex* destination;

	//Query structures
	std::vector       <Vertex*> visitedStations;
	std::forward_list <Vertex*> queue;

	//sets distance to infinity in all stations.
	void initialize ();
public:

	Algorithm  (Manager *man);
	~Algorithm();

	void addQuery (Vertex* orig, Vertex* dest);
	void runQuery();

};

