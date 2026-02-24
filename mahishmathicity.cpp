#include <iostream>
#include "mahishmathicity.h"

using namespace std;

// Constructor
MahishmathiCity::MahishmathiCity(char T, int P) {
    this->type = T;
    this->pollution = P;
}

// Setter for the city type
void MahishmathiCity::setType(char t) {
    this->type = t;
}

// Setter for pollution level
void MahishmathiCity::setPollution(int p) {
    this->pollution = p;
}

// Getter for city type, marked as const
char MahishmathiCity::getType() const {
    if (type != 'E') {
        return type;
    } else {
        return ' ';
    }
}

// Getter for pollution level, marked as const
int MahishmathiCity::getPollution() const {
    return pollution;
}

// Getter for the number of workers, marked as const
int MahishmathiCity::getWorkers() const {
    return workers;
}

// Getter for the number of goods, marked as const
int MahishmathiCity::getGoods() const {
    return goods;
}

// Getter for the population, marked as const
int MahishmathiCity::getPopulation() const {
    return population;
}

// Increment population count
void MahishmathiCity::updatePopulation() {
    population++;
}

// Check if cell is a powerline, marked as const
bool MahishmathiCity::isPowerline() const {
    return (type == 'T' || type == '#');
}

// Assign worker to MahishmathiCity element
void MahishmathiCity::assignWorker() {
    hasWorker = true;
    workers--;
}

// Assign good to MahishmathiCity element
void MahishmathiCity::assignGoods() {
    hasGood = true;
    goods--;
}
