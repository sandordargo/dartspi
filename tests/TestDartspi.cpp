#include "gtest/gtest.h"

#include <numbers>

#include "Dartspi.h"
#include "Point.h"


void assertPointIsWithinBoundaries(Point point, unsigned int side) {
    EXPECT_TRUE(point.x >= 0);
    EXPECT_TRUE(point.x <= side);
    EXPECT_TRUE(point.y >= 0);
    EXPECT_TRUE(point.y <= side);
}

TEST(DartspiTest, PiIsCalculatedWithHardcodedNumbers) {
    unsigned int numberOfDartsInCircle {785U};
    unsigned int totalNumberOfDarts {1'000U};
    ASSERT_NEAR(std::numbers::pi_v<double>, Dartspi::calculate(numberOfDartsInCircle, totalNumberOfDarts), 0.05);
}

TEST(DartspiTest, AllGeneratedPointsAreWithinBoundaries) {
    unsigned int side {100U};
    size_t numberOfPoints{1000U};
    std::vector<Point> points = Dartspi::generate(numberOfPoints, side);

    for(const auto& point: points) {
        assertPointIsWithinBoundaries(point, side);
    }
}

TEST(DartspiTest, PointIsWithinCircle) {
    Point aPoint{51, 49};
    Point center{50, 50};
    unsigned int radius{50};

    ASSERT_TRUE(Dartspi::pointWithinCircle(aPoint, center, radius));
}

TEST(DartspiTest, PointIsOutsideCircle) {
    Point aPoint{0, 0};
    Point center{50, 50};
    unsigned int radius{50};

    ASSERT_FALSE(Dartspi::pointWithinCircle(aPoint, center, radius));
}

TEST(DartspiTest, PointOnCircleIsConsideredOutside) {
    Point aPoint{50, 0};
    Point center{50, 50};
    unsigned int radius{50};

    ASSERT_FALSE(Dartspi::pointWithinCircle(aPoint, center, radius));
}

