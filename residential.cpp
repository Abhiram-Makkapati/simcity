#include "residential.h"
#include "main.h"
#include "analysis.h"

MahishmathiCity residentialProcess(MahishmathiCity& city, std::vector<std::vector<MahishmathiCity>>& Region, int x, int y) {
    MahishmathiCity newCity = city;

    if (city.getPopulation() == 0) {
        if (isAdjacentToPowerline(Region, x, y) || countAdjacentWithPopulation(Region, x, y, 1) >= 1) {
            newCity.updatePopulation();
            return newCity;
        }
        return newCity;
    } else if (city.getPopulation() == 1 && countAdjacentWithPopulation(Region, x, y, 1) >= 2) {
        newCity.updatePopulation();
        return newCity;
    } else if (city.getPopulation() == 2 && countAdjacentWithPopulation(Region, x, y, 2) >= 4) {
        newCity.updatePopulation();
        return newCity;
    } else if (city.getPopulation() == 3 && countAdjacentWithPopulation(Region, x, y, 3) >= 6) {
        newCity.updatePopulation();
        return newCity;
    } else if (city.getPopulation() == 4 && countAdjacentWithPopulation(Region, x, y, 4) >= 8) {
        newCity.updatePopulation();
        return newCity;
    }

    return newCity;
}
