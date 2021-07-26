#include "Dartspi.h"
#include <iostream>

namespace Dartspi {

double calculate(unsigned int numberOfDartsInCircle, 
                 unsigned int totalNumberOfDarts) {
    return (static_cast<double>(numberOfDartsInCircle) / totalNumberOfDarts) * 4;
}

}