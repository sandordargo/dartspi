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

TEST(DartspiTest, acceptanceTest) {
    unsigned int radius {500U};
    size_t numberOfPoints{1000000U};
    std::vector<Point> points = Dartspi::generatePointsWithinEnclosingSquare(numberOfPoints, radius);
    auto numberOfDartsInCircle = Dartspi::countPointsInCircle(points, radius);
    
    ASSERT_NEAR(std::numbers::pi_v<double>, Dartspi::calculatePi(numberOfDartsInCircle, numberOfPoints), 0.05);
}


TEST(DartspiTest, PiIsCalculatedWithHardcodedNumbers) {
    unsigned int numberOfDartsInCircle {785U};
    unsigned int totalNumberOfDarts {1'000U};
    ASSERT_NEAR(std::numbers::pi_v<double>, Dartspi::calculatePi(numberOfDartsInCircle, totalNumberOfDarts), 0.05);
}

TEST(DartspiTest, AllGeneratedPointsAreWithinBoundaries) {
    unsigned int radius {50U};
    size_t numberOfPoints{1000U};
    std::vector<Point> points = Dartspi::generatePointsWithinEnclosingSquare(numberOfPoints, radius);

    for(const auto& point: points) {
        assertPointIsWithinBoundaries(point, radius*2);
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

