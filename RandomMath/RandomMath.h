#pragma once

#include <algorithm>
#include <cmath>

namespace RandomMathWIP
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

	/// Refers to a 64-bit decimal parameter that's guaranteed to not need a bounds check. Use like: "InRangeDouble { 2.0 }".
	struct InRangeDouble { double sanitizedValue; };

	/// Refers to a 32-bit decimal parameter that's guaranteed to not need a bounds check. Use like: "InRangeFloat { 2.0f }".
	struct InRangeFloat { float sanitizedValue; };

	/// Refers to a signed integer parameter that's guaranteed to not need a bounds check. Use like: "InRangeDouble { 2.0 }".
	struct InRangeInt { int sanitizedValue; };

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

	// IsInteger
	/// Returns true if inValue does not have a fractional component.
	inline bool IsInteger(float inValue)
	{
		return std::floor(inValue) == inValue;
	}

	/// Returns true if inValue does not have a fractional component.
	inline bool IsInteger(double inValue)
	{
		return std::floor(inValue) == inValue;
	}

	// IsEven
	/// Returns true if inValue is even.
	inline bool IsEven(int inValue)
	{
		return inValue % 2 == 0;
	}

	/// Returns true if inValue is even and doesn't have a fractional component.
	inline bool IsEven(float inValue)
	{
		return IsInteger(inValue) && (std::remainder(inValue, 2.0f) == 0);
	}

	/// Returns true if inValue is even and doesn't have a fractional component.
	inline bool IsEven(double inValue)
	{
		return IsInteger(inValue) && (std::remainder(inValue, 2.0) == 0);
	}

	// IsOdd
	/// Returns true if inValue is odd.
	inline bool IsOdd(int inValue)
	{
		return inValue % 2 != 0;
	}

	/// Returns true if inValue is odd and doesn't have a fractional component.
	inline bool IsOdd(float inValue)
	{
		return IsInteger(inValue) && (std::remainder(inValue, 2.0f) != 0);
	}

	/// Returns true if inValue is odd and doesn't have a fractional component.
	inline bool IsOdd(double inValue)
	{
		return IsInteger(inValue) && (std::remainder(inValue, 2.0) != 0);
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

	// Lerp
	/// Returns inStart when inAlpha is 0. Returns inEnd when inAlpha is 1. Linearly interpolated between those points. Not clamped at inStart or inEnd.
	inline double Lerp(double inStart, double inEnd, double inAlpha)
	{
		return (inAlpha * inEnd) - ((inAlpha - 1) * inStart);
	}

	/// Returns inStart when inAlpha is 0. Returns inEnd when inAlpha is 1. Linearly interpolated between those points. Not clamped at inStart or inEnd.
	inline float Lerp(float inStart, float inEnd, float inAlpha)
	{
		return (inAlpha * inEnd) - ((inAlpha - 1) * inStart);
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

	/// Calculates shortest distance between two reduced points on a looping interval [0, inWrapValue)
	inline double ClockDistance(InRangeDouble inValueA, InRangeDouble inValueB, double inWrapValue)
	{
		double maxReducedPoint = std::max(inValueA.sanitizedValue, inValueB.sanitizedValue);
		double minReducedPoint = std::min(inValueA.sanitizedValue, inValueB.sanitizedValue);

		double distanceNoWrap = maxReducedPoint - minReducedPoint;
		double distanceWrap = (inWrapValue - maxReducedPoint) + minReducedPoint;

		return std::min(distanceNoWrap, distanceWrap);
	}

	/// Calculates shortest distance between two reduced points on a looping interval [0, inWrapValue)
	inline float ClockDistance(InRangeFloat inValueA, InRangeFloat inValueB, float inWrapValue)
	{
		float maxReducedPoint = std::max(inValueA.sanitizedValue, inValueB.sanitizedValue);
		float minReducedPoint = std::min(inValueA.sanitizedValue, inValueB.sanitizedValue);

		float distanceNoWrap = maxReducedPoint - minReducedPoint;
		float distanceWrap = (inWrapValue - maxReducedPoint) + minReducedPoint;

		return std::min(distanceNoWrap, distanceWrap);
	}

	/// Calculates shortest distance between two reduced points on a looping interval [0, inNumberOfSlices)
	inline int ClockDistance(InRangeInt inValueA, InRangeInt inValueB, int inNumberOfSlices)
	{
		int maxReducedPoint = std::max(inValueA.sanitizedValue, inValueB.sanitizedValue);
		int minReducedPoint = std::min(inValueA.sanitizedValue, inValueB.sanitizedValue);

		int distanceNoWrap = maxReducedPoint - minReducedPoint;
		int distanceWrap = (inNumberOfSlices - maxReducedPoint) + minReducedPoint;

		return std::min(distanceWrap, distanceNoWrap);
	}
}