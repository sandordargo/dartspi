#include "gtest/gtest.h"
#include "Dartspi.h"
#include <numbers>

TEST(blaTest, test1) {
    ASSERT_NEAR(std::numbers::pi_v<double>, Dartspi::calculate(), 0.05);
}
