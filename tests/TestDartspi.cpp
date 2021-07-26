#include "gtest/gtest.h"
#include "Dartspi.h"
#include <numbers>

TEST(DartspiTest, PiIsCalculatedWithHardcodedNumbers) {
    unsigned int numberOfDartsInCircle {785U};
    unsigned int totalNumberOfDarts {1'000U};
    ASSERT_NEAR(std::numbers::pi_v<double>, Dartspi::calculate(numberOfDartsInCircle, totalNumberOfDarts), 0.05);
}
