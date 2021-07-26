#include "Dartspi.h"

#include <random>

namespace Dartspi {

double calculate(unsigned int numberOfDartsInCircle, 
                 unsigned int totalNumberOfDarts) {
    return (static_cast<double>(numberOfDartsInCircle) / totalNumberOfDarts) * 4;
}

std::vector<Point> generate(size_t numberOfPoints, unsigned int side) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<unsigned int> dist(0, side);

    std::vector<Point> points;
    points.reserve(numberOfPoints);
    for(int i=0; i<numberOfPoints; ++i) {
        points.emplace_back(dist(mt), dist(mt));
    }

    return points;
}

}