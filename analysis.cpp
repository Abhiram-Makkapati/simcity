#include "analysis.h"

using namespace std;

bool isAdjacentToPowerline(vector<vector<MahishmathiCity>>& Region, int x, int y) {
    // Defines the directions for adjacent cells
    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    bool isAdjacentToPower = false;

//DEBUG    cout << "BASE :[" << y << ", " << x << "] " << Region[x][y].getType() << endl;
    
    for (int i = 0; i < 8; i++) {
        
        int adjX = x + directions[i][0];
        int adjY = y + directions[i][1];
        if ((adjY < Region.size() && adjY >= 0) && (adjX >= 0 && adjX < Region.size())) {

//DEBUG        cout << "CheckingType :[" << adjY << ", " << adjX << "] " << Region[adjX][adjY].getType() << endl;

            if (Region[adjX][adjY].isPowerline()) {
                isAdjacentToPower = true;
            }
        }
    }
    return isAdjacentToPower;
}

int countAdjacentWithPopulation(vector<vector<MahishmathiCity>>& Region, int x, int y, int minPopulation) {
    int count = 0;

    int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    for (int i = 0; i < 8; i++) {
        int adjX = x + directions[i][0];
        int adjY = y + directions[i][1];
        
        if (adjY >= 0 && adjY < Region.size() && adjX >= 0 && adjX < Region[0].size() && Region[adjY][adjX].getPopulation() >= minPopulation) {
            count++;
        }
    }
    return count;
}
