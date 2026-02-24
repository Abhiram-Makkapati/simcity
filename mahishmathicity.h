#ifndef MAHISHMATHICITY_H
#define MAHISHMATHICITY_H

#include <vector>
using namespace std;

class MahishmathiCity {
public:
    // Constructor with default values
    MahishmathiCity(char T = '\0', int P = 0);

    // Setter for the city type
    void setType(char t);

    // Setter for pollution level
    void setPollution(int p);

    // Getter for city type, marked as const
    char getType() const;

    // Getter for pollution level, marked as const
    int getPollution() const;

    // Getter for the number of workers, marked as const
    int getWorkers() const;

    // Getter for the number of goods, marked as const
    int getGoods() const;

    // Getter for the population, marked as const
    int getPopulation() const;

    // Increment population count
    void updatePopulation();
    
    // Check if adjacent cell is powerline, marked as const
    bool isPowerline() const;

    // Assign worker to MahishmathiCity element
    void assignWorker();
    
    // Assign good to MahishmathiCity element
    void assignGoods();

private:
    char type = '\0';
    int pollution = 0;
    int workers = 0;
    int goods = 0;
    int population = 0;
    bool hasWorker = false;
    bool hasGood = false;

    // Adjacency list to store neighboring cities
    vector<MahishmathiCity> adjacencyList;
};

#endif
