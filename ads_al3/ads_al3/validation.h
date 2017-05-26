#pragma once
#include <string>

//checks commandline parameters. Returns 0 in case of error.
int validate (int &argc, char** argv);

bool fexists (const std::string& filename);

void printHelp ();