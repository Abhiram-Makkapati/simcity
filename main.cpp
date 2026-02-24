#include "main.h"
#include "init.h" // Ensure necessary includes are present for called functions

void Print(int loop_value, vector<vector<MahishmathiCity>> &region) {
    // Print the current state of the region
    for (auto &row : region) {
        for (auto &city : row) {
            if (city.getType() == 'R' || city.getType() == 'C' || city.getType() == 'I') {
                if (city.getPopulation() == 0) {
                    cout << city.getType() << " ";
                } else {
                    cout << city.getPopulation() << " ";
                }
            } else {
                cout << city.getType() << " ";
            }
        }
        cout << endl;
    }
    cout << endl << "Timestep " << loop_value << " Pollution: " << GetTotalPollution(region);
}

int main() {
    vector<vector<MahishmathiCity>> Region;
    vector<vector<int>> mapKey;
    int timeLimit = 0;
    int refreshRate = 0;
    int initial = 0;

    // Read in files and initialize
    Initialize(Region, timeLimit, refreshRate, mapKey);

    for (int i = 0; i <= timeLimit; i++) {
        if (initial % refreshRate == 0) {
            Print(i, Region);
        }

        Simulation(mapKey, Region);
        initial++;
    }
    return 0;
}
