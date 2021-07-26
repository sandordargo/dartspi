#pragma once

#include <vector>

#include "Point.h"

namespace Dartspi {

double calculatePi(unsigned int numberOfDartsInCircle, 
                   unsigned int totalNumberOfDarts);

std::vector<Point> generate(size_t numberOfPoints, unsigned int side);

bool pointWithinCircle(Point aPoint, Point center, unsigned int radius);

size_t countPointsInCircle(std::vector<Point>, unsigned int side);

}
