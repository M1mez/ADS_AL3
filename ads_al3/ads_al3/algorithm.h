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

	void checkPathLength(Vertex* originVertex, Vertex* vertexToCheck, int newDistance);

	std::vector <Edge* > finish (Vertex* reachedGoal);
	void addToQueue (Vertex* addMeToQueue);

	//returns complementary edge of given Edge 'previous', for Vertex member previous
	Edge* turnPrevious(Vertex* originVertex);

public:

	Algorithm  (Manager *man);
	~Algorithm();

	void addQuery (Vertex* orig, Vertex* dest);
	//runs Query and returns route.
	std::vector <Edge* > runQuery();
	void reset (); // Hab ich in div. Methoden verteilt, war redundant

};

