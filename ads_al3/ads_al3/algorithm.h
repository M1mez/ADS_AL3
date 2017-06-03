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

	//Query structures.
	//Visited stations are rememberd to avoid placing then in the queue
	//Queue remembers all Vertex a path was found to. Ordered by pathLength, the total length of the shortest path found to this Vertex.
	std::vector <Vertex* > visitedStations;
	std::list <Vertex* > queue;

	//Checks if newly found path is shorter than the one before.
	void checkPathLength(Vertex* originVertex, Vertex* vertexToCheck, int newDistance);

	//Return the shortest path found to the manager.
	std::vector <Edge* > finish (Vertex* reachedGoal) const;

	//Adds a Vertex onto the queue.
	void addToQueue (Vertex* addMeToQueue);

	//Utility for Algorithm::finish ().
	//Returns Edge pointing to given Vertex, which was found in the Vertex 'Edge* previous' is pointing at.
	Edge* turnPrevious(Vertex* originVertex) const;

	//feed a new Query into the algorithm.
	void initializeQuery (Vertex* orig, Vertex* dest);
public:

	Algorithm  (Manager *man);
	~Algorithm();

	//runs Query and returns route.
	std::vector <Edge* > runQuery(Vertex* orig, Vertex* dest);

	//reset the vertices. IMPORTANT: Needs to be done after a query.
	void reset ();

};

