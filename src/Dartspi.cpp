#include "Dartspi.h"

#include <random>
#include <cmath>

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

bool pointWithinCircle(Point aPoint, Point center, unsigned int radius) {
    auto distance = ::sqrt(::pow(aPoint.x - center.x, 2) + ::pow(aPoint.y - center.y, 2));
    return distance < radius;
}

}