#include "commercial.h"
#include "analysis.h"

using namespace std;

MahishmathiCity commercialProcess(MahishmathiCity& city, vector<vector<MahishmathiCity>>& Region, int x, int y) {
    MahishmathiCity newCity = city;

    if (city.getPopulation() == 0) {
        if (isAdjacentToPowerline(Region, x, y) /* && city.getWorkers() >= 1 && city.getGoods() >= 1 */) {
            newCity.updatePopulation();
/*            newCity.assignWorker();
            newCity.assignGoods(); */
            return newCity;
        }
        return newCity;
    }
    else if (city.getPopulation() == 0 && countAdjacentWithPopulation(Region, x, y, 1) >= 2 /* && city.getWorkers() >= 1 && city.getGoods() >= 1 */) {
        newCity.updatePopulation();
/*        newCity.assignWorker();
        newCity.assignGoods(); */
        return newCity;
    }
    else if (city.getPopulation() == 1 && countAdjacentWithPopulation(Region, x, y, 2) >= 4 /* && city.getWorkers() >= 1 && city.getGoods() >= 1 */) {
        newCity.updatePopulation();
/*        newCity.assignWorker();
        newCity.assignGoods(); */
        return newCity;
    }

    return newCity;
}
