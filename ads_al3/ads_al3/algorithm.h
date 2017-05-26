#pragma once
#include "vertex.h"
#include "manager.h"

class Manager;

class Algorithm
{
private:
	Manager* manager;
public:

	Algorithm(Manager *man);
	~Algorithm();
	void test();


};

