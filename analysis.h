#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "main.h"
#include "init.h"
#include "mahishmathicity.h"
#include <vector>

using namespace std;

bool isAdjacentToPowerline(vector<vector<MahishmathiCity>>& Region, int x, int y);

int countAdjacentWithPopulation(vector<vector<MahishmathiCity>>& Region, int x, int y, int minPopulation);

#endif
