#pragma once

#include <vector>

#include "Point.h"

namespace Dartspi {

double calculatePi(unsigned int numberOfDartsInCircle, 
                   unsigned int totalNumberOfDarts);

std::vector<Point> generatePointsWithinEnclosingSquare(size_t numberOfPoints, 
                                                       unsigned int radius);

bool pointWithinCircle(Point aPoint, Point center, unsigned int radius);

size_t countPointsInCircle(std::vector<Point>, unsigned int radius);

}
