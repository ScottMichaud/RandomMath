#pragma once

#include <algorithm>
#include <cmath>

namespace RandomMath
{
	/// Refers to an "up-to and including" 64-bit decimal parameter (in math's interval notation: a square bracket). Use like: "InclusiveDouble { 2.0 }".
	struct InclusiveDouble { double boundaryToInclude; };

	/// Refers to an "up-to and including" 32-bit decimal parameter (in math's interval notation: a square bracket). Use like: "InclusiveFloat { 2.0f }".
	struct InclusiveFloat { float boundaryToInclude; };

	/// Refers to an "up-to and including" signed integer parameter (in math's interval notation: a square bracket). Use like: "InclusiveInt { 2 }".
	struct InclusiveInt { int boundaryToInclude; };

	/// Refers to an "up-to but excluding" 64-bit decimal parameter (in math's interval notation: a round bracket). Use like: "ExclusiveDouble { 2.0 }".
	struct ExclusiveDouble { double boundaryToExclude; };

	/// Refers to an "up-to but excluding" 32-bit decimal parameter (in math's interval notation: a round bracket). Use like: "ExclusiveFloat { 2.0f }".
	struct ExclusiveFloat { float boundaryToExclude; };

	/// Refers to an "up-to but excluding" signed integer parameter (in math's interval notation: a round bracket). Use like: "ExclusiveInt { 2 }".
	struct ExclusiveInt { int boundaryToExclude; };

	// IsBetween (Double)
	/// Returns true if inValue is inMin, inMax, or somewhere between inMin and inMax; false otherwise.
	inline bool IsBetween(double inValue, InclusiveDouble inMin, InclusiveDouble inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue <= inMax.boundaryToInclude;
	}

	/// Returns true if inValue is inMin or somewhere between inMin and inMax; false if it's inMax or otherwise.
	inline bool IsBetween(double inValue, InclusiveDouble inMin, ExclusiveDouble inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue < inMax.boundaryToExclude;
	}

	/// Returns true if inValue is inMax or somewhere between inMin and inMax; false if it's inMin or otherwise.
	inline bool IsBetween(double inValue, ExclusiveDouble inMin, InclusiveDouble inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue <= inMax.boundaryToInclude;
	}

	/// Returns true if inValue is between inMin and inMax; false if it's inMin, inMax, or otherwise.
	inline bool IsBetween(double inValue, ExclusiveDouble inMin, ExclusiveDouble inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue < inMax.boundaryToExclude;
	}

	// IsBetween (Float)
	/// Returns true if inValue is inMin, inMax, or somewhere between inMin and inMax; false otherwise.
	inline bool IsBetween(float inValue, InclusiveFloat inMin, InclusiveFloat inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue <= inMax.boundaryToInclude;
	}

	/// Returns true if inValue is inMin or somewhere between inMin and inMax; false if it's inMax or otherwise.
	inline bool IsBetween(float inValue, InclusiveFloat inMin, ExclusiveFloat inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue < inMax.boundaryToExclude;
	}

	/// Returns true if inValue is inMax or somewhere between inMin and inMax; false if it's inMin or otherwise.
	inline bool IsBetween(float inValue, ExclusiveFloat inMin, InclusiveFloat inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue <= inMax.boundaryToInclude;
	}

	/// Returns true if inValue is between inMin and inMax; false if it's inMin, inMax, or otherwise.
	inline bool IsBetween(float inValue, ExclusiveFloat inMin, ExclusiveFloat inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue < inMax.boundaryToExclude;
	}

	// IsBetween (Int)
	/// Returns true if inValue is inMin, inMax, or somewhere between inMin and inMax; false otherwise.
	inline bool IsBetween(int inValue, InclusiveInt inMin, InclusiveInt inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue <= inMax.boundaryToInclude;
	}

	/// Returns true if inValue is inMin or somewhere between inMin and inMax; false if it's inMax or otherwise.
	inline bool IsBetween(int inValue, InclusiveInt inMin, ExclusiveInt inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue < inMax.boundaryToExclude;
	}

	/// Returns true if inValue is inMax or somewhere between inMin and inMax; false if it's inMin or otherwise.
	inline bool IsBetween(int inValue, ExclusiveInt inMin, InclusiveInt inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue <= inMax.boundaryToInclude;
	}

	/// Returns true if inValue is between inMin and inMax; false if it's inMin, inMax, or otherwise.
	inline bool IsBetween(int inValue, ExclusiveInt inMin, ExclusiveInt inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue < inMax.boundaryToExclude;
	}

	// Clamp
	/// If inValue is lower than inMin, returns inMin. If inValue is higher than inMax, returns inMax. Returns inValue if it's between. NaN/etc. are not accounted for.
	inline double Clamp(double inValue, double inMin, double inMax)
	{
		return std::min(std::max(inValue, inMin), inMax);
	}

	/// If inValue is lower than inMin, returns inMin. If inValue is higher than inMax, returns inMax. Returns inValue if it's between. NaN/etc. are not accounted for.
	inline float Clamp(float inValue, float inMin, float inMax)
	{
		return std::min(std::max(inValue, inMin), inMax);
	}

	/// If inValue is lower than inMin, returns inMin. If inValue is higher than inMax, returns inMax. Returns inValue if it's between. NaN/etc. are not accounted for.
	inline int Clamp(int inValue, int inMin, int inMax)
	{
		return std::min(std::max(inValue, inMin), inMax);
	}

	// Positive Modulo
	/// Calculates the modulo and sanitizes negatives.
	
	/// If you visualize a clock face: asking -13 o'clock via PositiveModulo(-13, 12) would return 11 o'clock.
	inline double PositiveModulo(double inValue, double inWrapValue)
	{
		return std::fmod((std::fmod(inValue, inWrapValue) + inWrapValue), inWrapValue);
	}

	/// Calculates the modulo and sanitizes negatives.

	/// If you visualize a clock face: asking -13 o'clock via PositiveModulo(-13, 12) would return 11 o'clock.
	inline float PositiveModulo(float inValue, float inWrapValue)
	{
		return std::fmod((std::fmod(inValue, inWrapValue) + inWrapValue), inWrapValue);
	}

	/// Calculates the modulo and sanitizes negatives.

	/// If you visualize a clock face: asking -13 o'clock via PositiveModulo(-13, 12) would return 11 o'clock.
	inline int PositiveModulo(int inValue, int inNumberOfSlices)
	{
		return ((inValue % inNumberOfSlices) + inNumberOfSlices) % inNumberOfSlices;
	}

	/// Calculates the shortest distance between two values on an interval that infinitely loops between 0 and inWrapValue. (Ex: digits on a clock face)
	
	/// This is useful for calculating rotations. Ex: The Clock Distance between something turned 710 degrees (2
	/// full turns minus 10 degrees) and something turned 20 degrees (0 full turns and 20 degrees) is 30 degrees.
	/// You would use ClockDistance(710.0f, 20.0f, 360.0f) to calculate that value. Negatives inValues are valid.
	/// Distances are positive.
	inline double ClockDistance(double inValueA, double inValueB, double inWrapValue)
	{
		double reducedPointA = PositiveModulo(inValueA, inWrapValue);
		double reducedPointB = PositiveModulo(inValueB, inWrapValue);

		double maxReducedPoint = std::max(reducedPointA, reducedPointB);
		double minReducedPoint = std::min(reducedPointA, reducedPointB);

		double distanceNoWrap = maxReducedPoint - minReducedPoint;
		double distanceWrap = (inWrapValue - maxReducedPoint) + minReducedPoint;

		return std::min(distanceNoWrap, distanceWrap);
	}

	/// Calculates the shortest distance between two values on an interval that infinitely loops between 0 and inWrapValue. (Ex: digits on a clock face)

	/// This is useful for calculating rotations. Ex: The Clock Distance between something turned 710 degrees (2
	/// full turns minus 10 degrees) and something turned 20 degrees (0 full turns and 20 degrees) is 30 degrees.
	/// You would use ClockDistance(710.0f, 20.0f, 360.0f) to calculate that value. Negatives inValues are valid.
	/// Distances are positive.
	inline float ClockDistance(float inValueA, float inValueB, float inWrapValue)
	{
		float reducedPointA = PositiveModulo(inValueA, inWrapValue);
		float reducedPointB = PositiveModulo(inValueB, inWrapValue);

		float maxReducedPoint = std::max(reducedPointA, reducedPointB);
		float minReducedPoint = std::min(reducedPointA, reducedPointB);

		float distanceNoWrap = maxReducedPoint - minReducedPoint;
		float distanceWrap = (inWrapValue - maxReducedPoint) + minReducedPoint;

		return std::min(distanceNoWrap, distanceWrap);
	}

	/// Calculates the shortest distance between two values on an interval that infinitely loops between 0 and inWrapValue. (Ex: digits on a clock face)

	/// This is useful for calculating rotations. Ex: The Clock Distance between something turned 710 degrees (2
	/// full turns minus 10 degrees) and something turned 20 degrees (0 full turns and 20 degrees) is 30 degrees.
	/// You would use ClockDistance(710.0f, 20.0f, 360.0f) to calculate that value. Negatives inValues are valid.
	/// Distances are positive.
	inline int ClockDistance(int inValueA, int inValueB, int inNumberOfSlices)
	{
		int reducedPointA = PositiveModulo(inValueA, inNumberOfSlices);
		int reducedPointB = PositiveModulo(inValueB, inNumberOfSlices);

		int maxReducedPoint = std::max(reducedPointA, reducedPointB);
		int minReducedPoint = std::min(reducedPointA, reducedPointB);

		int distanceNoWrap = maxReducedPoint - minReducedPoint;
		int distanceWrap = (inNumberOfSlices - maxReducedPoint) + minReducedPoint;

		return std::min(distanceWrap, distanceNoWrap);
	}
}