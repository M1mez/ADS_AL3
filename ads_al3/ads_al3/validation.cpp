#include <iostream>
#include <string>
#include <fstream>
#include "validation.h"

void validate(int &argc, char* &argv)
{
	std::cout << "Test" <<std::endl;
}

bool fexists (const std::string& filename)
{
  std::ifstream ifile(filename.c_str());
  return (bool)ifile;
}