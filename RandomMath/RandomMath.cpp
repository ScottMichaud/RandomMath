#include "stdafx.h"
#include "RandomMath.h"

#include <algorithm>

int RandomMath::ClockDistance(int inPointA, int inPointB, int inNumberOfPoints)
{
	int reducedPointA = PositiveModulo(inPointA, inNumberOfPoints);
	int reducedPointB = PositiveModulo(inPointB, inNumberOfPoints);

	int maxReducedPoint = std::max(reducedPointA, reducedPointB);
	int minReducedPoint = std::min(reducedPointA, reducedPointB);

	int distanceNoWrap = abs(reducedPointB - reducedPointA);
	int distanceWrap = (inNumberOfPoints - maxReducedPoint) + minReducedPoint;

	return std::min(distanceWrap, distanceNoWrap);
}

int RandomMath::PositiveModulo(int inValue, int inNumberOfSlices)
{
	int modulo = inValue % inNumberOfSlices;

	if (modulo < 0)
	{
		return inNumberOfSlices + modulo;
	}

	return modulo;
}
