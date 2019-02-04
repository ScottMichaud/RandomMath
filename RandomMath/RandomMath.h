#pragma once
#include <inttypes.h>

namespace RandomMath
{
	double ClockDistance(double inValueA, double inValueB, double inWrapValue);
	float ClockDistance(float inValueA, float inValueB, float inWrapValue);
	int ClockDistance(int inValueA, int inValueB, int inNumberOfSlice);
	int PositiveModulo(int inValue, int inNumberOfSlices);
}