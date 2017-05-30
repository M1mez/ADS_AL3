#pragma once
#include <vector>
#include <list>
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
	std::vector <Vertex* > visitedStations;
	std::list <Vertex* > queue;

	//sets distance to infinity in all stations.
	// void initialize ();  // Hab ich in div. Methoden verteilt, war redundant

	void checkPathLength(Edge* previousEdge, Vertex* vertexToCheck, int newDistance);

	//std::vector <Vertex* > finish (Vertex* reachedGoal); // noch benötigt?
	void addToQueue (Vertex* addMeToQueue);
public:

	Algorithm  (Manager *man);
	~Algorithm();

	void addQuery (Vertex* orig, Vertex* dest);
	//runs Query and returns route.
	std::vector <Vertex* > runQuery();

};

