#pragma once

namespace RandomMath
{
	double ClockDistance(double inValueA, double inValueB, double inWrapValue);
	float ClockDistance(float inValueA, float inValueB, float inWrapValue);
	int ClockDistance(int inValueA, int inValueB, int inNumberOfSlice);
	double PositiveModulo(double inValue, double inNumberOfSlices);
	float PositiveModulo(float inValue, float inNumberOfSlices);
	int PositiveModulo(int inValue, int inNumberOfSlices);
}