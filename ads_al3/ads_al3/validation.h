#pragma once
#include <string>
#include <map>
#include "vertex.h"

//checks commandline parameters. Returns 0 in case of error.
int validate (int &argc, char** argv);

bool fexists (const std::string& filename);

void printHelp ();

bool validateUserQuery(std::string start, std::string end, const std::map< std::string, Vertex* > &m_stations);