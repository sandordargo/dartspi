#pragma once

#include <vector>

#include "Point.h"

namespace Dartspi {

double calculate(unsigned int numberOfDartsInCircle, 
                 unsigned int totalNumberOfDarts);

std::vector<Point> generate(size_t numberOfPoints, unsigned int side);

bool pointWithinCircle(Point aPoint, Point center, unsigned int radius);

}
