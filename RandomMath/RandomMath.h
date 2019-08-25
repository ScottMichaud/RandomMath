#pragma once

#include <algorithm>
#include <cmath>

namespace RandomMathWIP
{
	namespace IncludeStartIncludeEnd {
		/// Returns true if inValue is inMin, inMax, or somewhere between inMin and inMax; false otherwise.
		inline bool IsBetween(double inValue, double inMin, double inMax)
		{
			return inValue >= inMin && inValue <= inMax;
		}

		/// Returns true if inValue is inMin, inMax, or somewhere between inMin and inMax; false otherwise.
		inline bool IsBetween(float inValue, float inMin, float inMax)
		{
			return inValue >= inMin && inValue <= inMax;
		}

		/// Returns true if inValue is inMin, inMax, or somewhere between inMin and inMax; false otherwise.
		inline bool IsBetween(int inValue, int inMin, int inMax)
		{
			return inValue >= inMin && inValue <= inMax;
		}
	}

	namespace IncludeStartExcludeEnd {
		/// Returns true if inValue is inMin or somewhere between inMin and inMax; false if it's inMax or otherwise.
		inline bool IsBetween(double inValue, double inMin, double inMax)
		{
			return inValue >= inMin && inValue < inMax;
		}

		/// Returns true if inValue is inMin or somewhere between inMin and inMax; false if it's inMax or otherwise.
		inline bool IsBetween(float inValue, float inMin, float inMax)
		{
			return inValue >= inMin && inValue < inMax;
		}

		/// Returns true if inValue is inMin or somewhere between inMin and inMax; false if it's inMax or otherwise.
		inline bool IsBetween(int inValue, int inMin, int inMax)
		{
			return inValue >= inMin && inValue < inMax;
		}
	}

	namespace ExcludeStartIncludeEnd {
		/// Returns true if inValue is inMax or somewhere between inMin and inMax; false if it's inMin or otherwise.
		inline bool IsBetween(double inValue, double inMin, double inMax)
		{
			return inValue > inMin && inValue <= inMax;
		}

		/// Returns true if inValue is inMax or somewhere between inMin and inMax; false if it's inMin or otherwise.
		inline bool IsBetween(float inValue, float inMin, float inMax)
		{
			return inValue > inMin && inValue <= inMax;
		}

		/// Returns true if inValue is inMax or somewhere between inMin and inMax; false if it's inMin or otherwise.
		inline bool IsBetween(int inValue, int inMin, int inMax)
		{
			return inValue > inMin && inValue <= inMax;
		}
	}

	namespace ExcludeStartExcludeEnd {
		/// Returns true if inValue is between inMin and inMax; false if it's inMin, inMax, or otherwise.
		inline bool IsBetween(double inValue, double inMin, double inMax)
		{
			return inValue > inMin && inValue < inMax;
		}

		/// Returns true if inValue is between inMin and inMax; false if it's inMin, inMax, or otherwise.
		inline bool IsBetween(float inValue, float inMin, float inMax)
		{
			return inValue > inMin && inValue < inMax;
		}

		/// Returns true if inValue is between inMin and inMax; false if it's inMin, inMax, or otherwise.
		inline bool IsBetween(int inValue, int inMin, int inMax)
		{
			return inValue > inMin && inValue < inMax;
		}
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

	/// Calculates the shortest distance between two values on an interval that infinitely loops between 0 and inWrapValue. (Ex: digits on a clock face) Use Reduced::ClockDistance() if the inputs are guaranteed to be between [0, inWrapValue).
	
	/// This is useful for calculating rotations. Ex: The Clock Distance between something turned 710 degrees (2
	/// full turns minus 10 degrees) and something turned 20 degrees (0 full turns and 20 degrees) is 30 degrees.
	/// You would use ClockDistance(710.0f, 20.0f, 360.0f) to calculate that value. inValueA and inValueB can be
	/// negative. Distances are positive.
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

	/// Calculates the shortest distance between two values on an interval that infinitely loops between 0 and inWrapValue. (Ex: digits on a clock face) Use Reduced::ClockDistance() if the inputs are guaranteed to be between [0, inWrapValue).

	/// This is useful for calculating rotations. Ex: The Clock Distance between something turned 710 degrees (2
	/// full turns minus 10 degrees) and something turned 20 degrees (0 full turns and 20 degrees) is 30 degrees.
	/// You would use ClockDistance(710.0f, 20.0f, 360.0f) to calculate that value. inValueA and inValueB can be
	/// negative. Distances are positive.
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

	/// Calculates the shortest distance between two values on an interval that infinitely loops between 0 and inWrapValue. (Ex: digits on a clock face) Use Reduced::ClockDistance() if the inputs are guaranteed to be between [0, inNumberOfSlices).

	/// This is useful for calculating rotations. Ex: The Clock Distance between something turned 710 degrees (2
	/// full turns minus 10 degrees) and something turned 20 degrees (0 full turns and 20 degrees) is 30 degrees.
	/// You would use ClockDistance(710.0f, 20.0f, 360.0f) to calculate that value. inValueA and inValueB can be
	/// negative. Distances are positive.
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

	namespace Reduced {
		/// Calculates shortest distance between two reduced (within the first iteration of the interval) points on a looping interval [0, inWrapValue)
		inline double ClockDistance(double inValueA, double inValueB, double inWrapValue)
		{
			// Testing optimization
			//double distance = inValueA - inValueB;

			//if (distance < 0) {
			//	return (-distance < (inWrapValue + distance)) ? -distance : (inWrapValue + distance);
			//}
			//else {
			//	return (distance < inWrapValue - distance) ? distance : (inWrapValue - distance);
			//}

			//---------

			//double distance = inValueA - inValueB;

			//if (distance < 0) {
            //    double otherDir = inWrapValue + distance;
			//	return (-distance < otherDir) ? -distance : otherDir;
			//}
			//else {
            //    double otherDir = inWrapValue - distance;
			//	return (distance < otherDir) ? distance : otherDir;
			//}


			double maxReducedPoint = std::max(inValueA, inValueB);
			double minReducedPoint = std::min(inValueA, inValueB);

			double distanceNoWrap = maxReducedPoint - minReducedPoint;
			double distanceWrap = (inWrapValue - maxReducedPoint) + minReducedPoint;

			return std::min(distanceNoWrap, distanceWrap);
		}

		/// Calculates shortest distance between two reduced (within the first iteration of the interval) points on a looping interval [0, inWrapValue)
		inline float ClockDistance(float inValueA, float inValueB, float inWrapValue)
		{
			float maxReducedPoint = std::max(inValueA, inValueB);
			float minReducedPoint = std::min(inValueA, inValueB);

			float distanceNoWrap = maxReducedPoint - minReducedPoint;
			float distanceWrap = (inWrapValue - maxReducedPoint) + minReducedPoint;

			return std::min(distanceNoWrap, distanceWrap);
		}

		/// Calculates shortest distance between two reduced (within the first iteration of the interval) points on a looping interval [0, inNumberOfSlices)
		inline int ClockDistance(int inValueA, int inValueB, int inNumberOfSlices)
		{
			int maxReducedPoint = std::max(inValueA, inValueB);
			int minReducedPoint = std::min(inValueA, inValueB);

			int distanceNoWrap = maxReducedPoint - minReducedPoint;
			int distanceWrap = (inNumberOfSlices - maxReducedPoint) + minReducedPoint;

			return std::min(distanceWrap, distanceNoWrap);
		}
	}
}