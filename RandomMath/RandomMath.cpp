#include "stdafx.h"
#include "RandomMath.h"

double RandomMath::ClockDistance(double inPointA, double inPointB, double inWrapValue)
{
	double reducedPointA = PositiveModulo(inPointA, inWrapValue);
	double reducedPointB = PositiveModulo(inPointB, inWrapValue);

	double maxReducedPoint = std::max(reducedPointA, reducedPointB);
	double minReducedPoint = std::min(reducedPointA, reducedPointB);

	double distanceNoWrap = maxReducedPoint - minReducedPoint;
	double distanceWrap = (inWrapValue - maxReducedPoint) + minReducedPoint;

	return std::min(distanceNoWrap, distanceWrap);
}

float RandomMath::ClockDistance(float inPointA, float inPointB, float inWrapValue)
{
	float reducedPointA = PositiveModulo(inPointA, inWrapValue);
	float reducedPointB = PositiveModulo(inPointB, inWrapValue);

	float maxReducedPoint = std::max(reducedPointA, reducedPointB);
	float minReducedPoint = std::min(reducedPointA, reducedPointB);

	float distanceNoWrap = maxReducedPoint - minReducedPoint;
	float distanceWrap = (inWrapValue - maxReducedPoint) + minReducedPoint;

	return std::min(distanceNoWrap, distanceWrap);
}

int RandomMath::ClockDistance(int inPointA, int inPointB, int inNumberOfPoints)
{
	int reducedPointA = PositiveModulo(inPointA, inNumberOfPoints);
	int reducedPointB = PositiveModulo(inPointB, inNumberOfPoints);

	int maxReducedPoint = std::max(reducedPointA, reducedPointB);
	int minReducedPoint = std::min(reducedPointA, reducedPointB);

	int distanceNoWrap = maxReducedPoint - minReducedPoint;
	int distanceWrap = (inNumberOfPoints - maxReducedPoint) + minReducedPoint;

	return std::min(distanceWrap, distanceNoWrap);
}