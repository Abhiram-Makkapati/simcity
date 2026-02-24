#include "industrial.h"
#include "analysis.h"

using namespace std;

/// Function to calculate pollution generation and spread
void calculatePollution(vector<vector<MahishmathiCity>>& Region, int x, int y) {
    int population = Region[x][y].getPopulation();

    if (population > 0) {
        int pollution = population;

        // Define the directions for adjacent cells
        int directions[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

        for (int i = 0; i < 8; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            if (newY >= 0 && newY < Region.size() && newX >= 0 && newX < Region[0].size()) {
                // Pollution spreads to adjacent cells at a rate of one less unit of pollution per cell away from the source
                Region[newY][newX].setPollution(pollution - 1);
            }
        }
    }
}

// Function to handle the generation and distribution of goods from industrial zones
void generateAndDistributeGoods(vector<vector<MahishmathiCity>>& Region, int x, int y, vector<vector<int>> mapKey) {
    int industrialPopulation = Region[y][x].getPopulation();

    if (industrialPopulation > 0) {
        int goodsProduced = industrialPopulation;

        // Define the directions for adjacent cells
        int directions[8][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

        for (int i = 0; i < 8; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            if (newY >= 0 && newY < Region.size() && newX >= 0 && newX < Region[0].size()) {
                // Check if the adjacent cell is a commercial zone
                if (mapKey[newY][newX] == 3) {
                    // Distribute good to the commercial cell
                    Region[newY][newX].assignGoods();
                    goodsProduced--;

                    // Stop distributing goods if all goods have been distributed
                    if (goodsProduced <= 0) {
                        break;
                    }
                }
            }
        }
    }
}

MahishmathiCity industrialProcess(MahishmathiCity& city, vector<vector<MahishmathiCity>>& Region, int x, int y) {
    MahishmathiCity newCity = city;

    if (city.getPopulation() == 0) {
        if (isAdjacentToPowerline(Region, x, y) /*&& available workers >= 2*/) {
            newCity.updatePopulation();
            // Assign available workers to this cell and subtract them from the total
            // Set goods equal to the population value of the new city
            return newCity;
        }
        else if (countAdjacentWithPopulation(Region, x, y, 1) >= 1 /*&& available workers >= 2*/) {
            newCity.updatePopulation();
            // Assign available workers to this cell and subtract them from the total
            return newCity;
        }
        return newCity;
    }
    else if (city.getPopulation() == 1 && countAdjacentWithPopulation(Region, x, y, 1) >= 2 /*&& available workers >= 2*/) {
        newCity.updatePopulation();
        // Assign available workers to this cell and subtract them from the total
        return newCity;
    }
    else if (city.getPopulation() == 2 && countAdjacentWithPopulation(Region, x, y, 2) >= 4 /*&& available workers >= 2*/) {
        newCity.updatePopulation();
        // Assign available workers to this cell and subtract them from the total
        return newCity;
    }

    return newCity;
}
