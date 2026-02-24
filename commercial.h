#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "mahishmathicity.h"
#include "main.h"
#include <vector>

using namespace std;

// Helper function to check if a cell is adjacent to a powerline
bool isAdjacentToPowerline(vector<vector<MahishmathiCity>>& Region, int x, int y);

// Function to count adjacent cells of a certain population or more
int countAdjacentWithPopulation(vector<vector<MahishmathiCity>>& Region, int x, int y, int minPopulation);

// Main processing function for a commercial zone
MahishmathiCity commercialProcess(MahishmathiCity& city, vector<vector<MahishmathiCity>>& Region, int x, int y);

#endif
