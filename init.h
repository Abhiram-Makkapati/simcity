#ifndef INIT_H
#define INIT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "mahishmathicity.h"

using namespace std;

// Function to parse a configuration line in a config file
string ParseConfigLine(string configLine);

// Function to parse a region line from a CSV file and create MahishmathiCity objects
void ParseRegionLine(string &regionLine, vector<MahishmathiCity> &row);

// Function to parse the config file at the beginning of the program
void ParseConfigFile(string configFileName, string &regionFileName, int &timeLimit, int &refreshRate);

// Function to parse the region data from a CSV file
void ParseRegionFile(vector<vector<MahishmathiCity>> &Region, string regionFileName);

// Function to calculate the total pollution in the region
int GetTotalPollution(vector<vector<MahishmathiCity>> &Region);

// Main initialization function
void Initialize(vector<vector<MahishmathiCity>> &Region, int &timeLimit, int &refreshRate, vector<vector<int>> &mapKey);

// Function to run the simulation
void Simulation(vector<vector<int>> mapKey, vector<vector<MahishmathiCity>> &Region);

// Function to find adjacent tiles in the region
void FindAdjacentTiles(vector<vector<MahishmathiCity>> &vect);

#endif
