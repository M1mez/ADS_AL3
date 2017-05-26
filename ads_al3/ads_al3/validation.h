#pragma once

//checks commandline parameters
void validate(int &argc, char* &argv);

//checks existance of File
bool fexists(const std::string& filename);