#pragma once

#include <algorithm>
#include <cmath>

namespace RandomMathWIP
{
	namespace IncludeStartIncludeEnd {
		/// Returns true if inValue is inMin, inMax, or somewhere between inMin and inMax; false otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, inclusive
		///\param inMax The maximum value, inclusive
		///\return true if inValue is inMax, inMin, or somewhere between
		inline bool IsBetween(double inValue, double inMin, double inMax)
		{
			return inValue >= inMin && inValue <= inMax;
		}

		/// Returns true if inValue is inMin, inMax, or somewhere between inMin and inMax; false otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, inclusive
		///\param inMax The maximum value, inclusive
		///\return true if inValue is inMax, inMin, or somewhere between
		inline bool IsBetween(float inValue, float inMin, float inMax)
		{
			return inValue >= inMin && inValue <= inMax;
		}

		/// Returns true if inValue is inMin, inMax, or somewhere between inMin and inMax; false otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, inclusive
		///\param inMax The maximum value, inclusive
		///\return true if inValue is inMax, inMin, or somewhere between
		inline bool IsBetween(int inValue, int inMin, int inMax)
		{
			return inValue >= inMin && inValue <= inMax;
		}
	}

	namespace IncludeStartExcludeEnd {
		/// Returns true if inValue is inMin or somewhere between inMin and inMax; false if it's inMax or otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, inclusive
		///\param inMax The maximum value, exclusive
		///\return true if inValue is inMin, or somewhere between inMin and inMax
		inline bool IsBetween(double inValue, double inMin, double inMax)
		{
			return inValue >= inMin && inValue < inMax;
		}

		/// Returns true if inValue is inMin or somewhere between inMin and inMax; false if it's inMax or otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, inclusive
		///\param inMax The maximum value, exclusive
		///\return true if inValue is inMin, or somewhere between inMin and inMax
		inline bool IsBetween(float inValue, float inMin, float inMax)
		{
			return inValue >= inMin && inValue < inMax;
		}

		/// Returns true if inValue is inMin or somewhere between inMin and inMax; false if it's inMax or otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, inclusive
		///\param inMax The maximum value, exclusive
		///\return true if inValue is inMin, or somewhere between inMin and inMax
		inline bool IsBetween(int inValue, int inMin, int inMax)
		{
			return inValue >= inMin && inValue < inMax;
		}
	}

	namespace ExcludeStartIncludeEnd {
		/// Returns true if inValue is inMax or somewhere between inMin and inMax; false if it's inMin or otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, exclusive
		///\param inMax The maximum value, inclusive
		///\return true if inValue is inMax, or somewhere between inMin and inMax
		inline bool IsBetween(double inValue, double inMin, double inMax)
		{
			return inValue > inMin && inValue <= inMax;
		}

		/// Returns true if inValue is inMax or somewhere between inMin and inMax; false if it's inMin or otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, exclusive
		///\param inMax The maximum value, inclusive
		///\return true if inValue is inMax, or somewhere between inMin and inMax
		inline bool IsBetween(float inValue, float inMin, float inMax)
		{
			return inValue > inMin && inValue <= inMax;
		}

		/// Returns true if inValue is inMax or somewhere between inMin and inMax; false if it's inMin or otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, exclusive
		///\param inMax The maximum value, inclusive
		///\return true if inValue is inMax, or somewhere between inMin and inMax
		inline bool IsBetween(int inValue, int inMin, int inMax)
		{
			return inValue > inMin && inValue <= inMax;
		}
	}

	namespace ExcludeStartExcludeEnd {
		/// Returns true if inValue is between inMin and inMax; false if it's inMin, inMax, or otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, exclusive
		///\param inMax The maximum value, exclusive
		///\return true if inValue is somewhere between inMin and inMax, but not inMin or inMax
		inline bool IsBetween(double inValue, double inMin, double inMax)
		{
			return inValue > inMin && inValue < inMax;
		}

		/// Returns true if inValue is between inMin and inMax; false if it's inMin, inMax, or otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, exclusive
		///\param inMax The maximum value, exclusive
		///\return true if inValue is somewhere between inMin and inMax, but not inMin or inMax
		inline bool IsBetween(float inValue, float inMin, float inMax)
		{
			return inValue > inMin && inValue < inMax;
		}

		/// Returns true if inValue is between inMin and inMax; false if it's inMin, inMax, or otherwise.
		///\param inValue The value to check
		///\param inMin The minimum value, exclusive
		///\param inMax The maximum value, exclusive
		///\return true if inValue is somewhere between inMin and inMax, but not inMin or inMax
		inline bool IsBetween(int inValue, int inMin, int inMax)
		{
			return inValue > inMin && inValue < inMax;
		}
	}

	// IsInteger
	/// Returns true if inValue does not have a fractional component.
	///\param inValue The value to check
	///\return true if inValue is an integer
	inline bool IsInteger(float inValue)
	{
		return (int)inValue == inValue;
	}

	/// Returns true if inValue does not have a fractional component.
	///\param inValue The value to check
	///\return true if inValue is an integer
	inline bool IsInteger(double inValue)
	{
		return (int)inValue == inValue;
	}

	// IsEven
	/// Returns true if inValue is even.
	///\param inValue The value to check
	///\return true if inValue is even
	inline bool IsEven(int inValue)
	{
		return inValue % 2 == 0;
	}

	/// Returns true if inValue is even and doesn't have a fractional component.
	///\param inValue The value to check
	///\return true if inValue is an integer and even
	inline bool IsEven(float inValue)
	{
		return ((int)inValue == inValue) && (std::fmod(inValue, 2.0f) == 0);
	}

	/// Returns true if inValue is even and doesn't have a fractional component.
	///\param inValue The value to check
	///\return true if inValue is an integer and even
	inline bool IsEven(double inValue)
	{
		return ((int)inValue == inValue) && (std::fmod(inValue, 2.0) == 0);
	}

	// IsOdd
	/// Returns true if inValue is odd.
	///\param inValue The value to check
	///\return true if inValue is odd
	inline bool IsOdd(int inValue)
	{
		return inValue % 2 != 0;
	}

	/// Returns true if inValue is odd and doesn't have a fractional component.
	///\param inValue The value to check
	///\return true if inValue is an integer and odd
	inline bool IsOdd(float inValue)
	{
		return ((int)inValue == inValue) && (std::fmod(inValue, 2.0f) != 0);
	}

	/// Returns true if inValue is odd and doesn't have a fractional component.
	///\param inValue The value to check
	///\return true if inValue is an integer and odd
	inline bool IsOdd(double inValue)
	{
		return ((int)inValue == inValue) && (std::fmod(inValue, 2.0) != 0);
	}

	// Clamp
	/// If inValue is lower than inMin, returns inMin. If inValue is higher than inMax, returns inMax. Returns inValue if it's between. NaN/etc. are not accounted for.
	///\param inValue The value to clamp
	///\param inMin The minimum value
	///\param inMax The maximum value
	///\return inValue if it is between inMin and inMax, otherwise inMin or inMax (whichever is closer)
	inline double Clamp(double inValue, double inMin, double inMax)
	{
		return std::min(std::max(inValue, inMin), inMax);
	}

	/// If inValue is lower than inMin, returns inMin. If inValue is higher than inMax, returns inMax. Returns inValue if it's between. NaN/etc. are not accounted for.
	///\param inValue The value to clamp
	///\param inMin The minimum value
	///\param inMax The maximum value
	///\return inValue if it is between inMin and inMax, otherwise inMin or inMax (whichever is closer)
	inline float Clamp(float inValue, float inMin, float inMax)
	{
		return std::min(std::max(inValue, inMin), inMax);
	}

	/// If inValue is lower than inMin, returns inMin. If inValue is higher than inMax, returns inMax. Returns inValue if it's between. NaN/etc. are not accounted for.
	///\param inValue The value to clamp
	///\param inMin The minimum value
	///\param inMax The maximum value
	///\return inValue if it is between inMin and inMax, otherwise inMin or inMax (whichever is closer)
	inline int Clamp(int inValue, int inMin, int inMax)
	{
		return std::min(std::max(inValue, inMin), inMax);
	}

	// Lerp
	/// Returns inStart when inAlpha is 0. Returns inEnd when inAlpha is 1. Linearly interpolated between those points. Not clamped at inStart or inEnd.
	///\param inStart Will be returned when inAlpha is 0
	///\param inEnd Will be returned when inAlpha is 1
	///\param inAlpha The progress between inStart and inEnd, measured in [0, 1].
	///\return The progress between inStart and inEnd (or beyond when inAlpha is outside of [0, 1])
	inline double Lerp(double inStart, double inEnd, double inAlpha)
	{
		return (inAlpha * inEnd) - ((inAlpha - 1) * inStart);
	}

	/// Returns inStart when inAlpha is 0. Returns inEnd when inAlpha is 1. Linearly interpolated between those points. Not clamped at inStart or inEnd.
	///\param inStart Will be returned when inAlpha is 0
	///\param inEnd Will be returned when inAlpha is 1
	///\param inAlpha The progress between inStart and inEnd, measured in [0, 1].
	///\return The progress between inStart and inEnd (or beyond when inAlpha is outside of [0, 1])
	inline float Lerp(float inStart, float inEnd, float inAlpha)
	{
		return (inAlpha * inEnd) - ((inAlpha - 1) * inStart);
	}

	// Positive Modulo
	/// Calculates the modulo and sanitizes negatives.
	
	/// If you visualize a clock face: asking -13 o'clock via PositiveModulo(-13, 12) would return 11 o'clock.
	///\param inValue The value to modify
	///\param inWrapValue The maximum value (the minimum is always 0)
	///\return The value wrapped around the circle from 0 to inWrapValue
	inline double PositiveModulo(double inValue, double inWrapValue)
	{
		return std::fmod((std::fmod(inValue, inWrapValue) + inWrapValue), inWrapValue);
	}

	/// Calculates the modulo and sanitizes negatives.

	/// If you visualize a clock face: asking -13 o'clock via PositiveModulo(-13, 12) would return 11 o'clock.
	///\param inValue The value to modify
	///\param inWrapValue The maximum value (the minimum is always 0)
	///\return The value wrapped around the circle from 0 to inWrapValue
	inline float PositiveModulo(float inValue, float inWrapValue)
	{
		return std::fmod((std::fmod(inValue, inWrapValue) + inWrapValue), inWrapValue);
	}

	/// Calculates the modulo and sanitizes negatives.

	/// If you visualize a clock face: asking -13 o'clock via PositiveModulo(-13, 12) would return 11 o'clock.
	///\param inValue The value to modify
	///\param inNumberOfSlices The maximum value (the minimum is always 0)
	///\return The value wrapped around the circle from 0 to inNumberOfSlices
	inline int PositiveModulo(int inValue, int inNumberOfSlices)
	{
		return ((inValue % inNumberOfSlices) + inNumberOfSlices) % inNumberOfSlices;
	}

	/// Calculates the shortest distance between two values on an interval that infinitely loops between 0 and inWrapValue. (Ex: digits on a clock face) Use Reduced::ClockDistance() if the inputs are guaranteed to be between [0, inWrapValue).
	
	/// This is useful for calculating rotations. Ex: The Clock Distance between something turned 710 degrees (2
	/// full turns minus 10 degrees) and something turned 20 degrees (0 full turns and 20 degrees) is 30 degrees.
	/// You would use ClockDistance(710.0f, 20.0f, 360.0f) to calculate that value. inValueA and inValueB can be
	/// negative. Distances are positive.
	///\param inValueA The first value (can be larger than inWrapValue)
	///\param inValueB The second value (can be larger than inWrapValue)
	///\param inWrapValue The maximum value (the minimum is always 0)
	///\return The distance between inValueA and inValueB on the circle 0 to inWrapValue
	inline double ClockDistance(double inValueA, double inValueB, double inWrapValue)
	{
		double reducedPointA = PositiveModulo(inValueA, inWrapValue);
		double reducedPointB = PositiveModulo(inValueB, inWrapValue);

		double distance = reducedPointA - reducedPointB;

		if (distance < 0) {
			double otherDir = inWrapValue + distance;
			return (-distance < otherDir) ? -distance : otherDir;
		}
		else {
			double otherDir = inWrapValue - distance;
			return (distance < otherDir) ? distance : otherDir;
		}
	}

	/// Calculates the shortest distance between two values on an interval that infinitely loops between 0 and inWrapValue. (Ex: digits on a clock face) Use Reduced::ClockDistance() if the inputs are guaranteed to be between [0, inWrapValue).

	/// This is useful for calculating rotations. Ex: The Clock Distance between something turned 710 degrees (2
	/// full turns minus 10 degrees) and something turned 20 degrees (0 full turns and 20 degrees) is 30 degrees.
	/// You would use ClockDistance(710.0f, 20.0f, 360.0f) to calculate that value. inValueA and inValueB can be
	/// negative. Distances are positive.
	///\param inValueA The first value (can be larger than inWrapValue)
	///\param inValueB The second value (can be larger than inWrapValue)
	///\param inWrapValue The maximum value (the minimum is always 0)
	///\return The distance between inValueA and inValueB on the circle 0 to inWrapValue
	inline float ClockDistance(float inValueA, float inValueB, float inWrapValue)
	{
		float reducedPointA = PositiveModulo(inValueA, inWrapValue);
		float reducedPointB = PositiveModulo(inValueB, inWrapValue);

		float distance = reducedPointA - reducedPointB;
		if (distance < 0) {
			float otherDir = inWrapValue + distance;
			return (-distance < otherDir) ? -distance : otherDir;
		}
		else {
			float otherDir = inWrapValue - distance;
			return (distance < otherDir) ? distance : otherDir;
		}
	}

	/// Calculates the shortest distance between two values on an interval that infinitely loops between 0 and inWrapValue. (Ex: digits on a clock face) Use Reduced::ClockDistance() if the inputs are guaranteed to be between [0, inNumberOfSlices).

	/// This is useful for calculating rotations. Ex: The Clock Distance between something turned 710 degrees (2
	/// full turns minus 10 degrees) and something turned 20 degrees (0 full turns and 20 degrees) is 30 degrees.
	/// You would use ClockDistance(710.0f, 20.0f, 360.0f) to calculate that value. inValueA and inValueB can be
	/// negative. Distances are positive.
	///\param inValueA The first value (can be larger than inNumberOfSlices)
	///\param inValueB The second value (can be larger than inNumberOfSlices)
	///\param inNumberOfSlices The maximum value (the minimum is always 0)
	///\return The distance between inValueA and inValueB on the circle 0 to inNumberOfSlices
	inline int ClockDistance(int inValueA, int inValueB, int inNumberOfSlices)
	{
		int reducedPointA = PositiveModulo(inValueA, inNumberOfSlices);
		int reducedPointB = PositiveModulo(inValueB, inNumberOfSlices);

		int distance = reducedPointA - reducedPointB;

		if (distance < 0) {
			int otherDir = inNumberOfSlices + distance;
			return (-distance < otherDir) ? -distance : otherDir;
		}
		else {
			int otherDir = inNumberOfSlices - distance;
			return (distance < otherDir) ? distance : otherDir;
		}
	}

	namespace Reduced {
		/// Calculates shortest distance between two reduced (within the first iteration of the interval) points on a looping interval [0, inWrapValue)
		///\param inValueA The first value (must be smaller than inWrapValue)
		///\param inValueB The second value (must be smaller than inWrapValue)
		///\param inWrapValue The maximum value (the minimum is always 0)
		///\return The distance between inValueA and inValueB on the circle 0 to inWrapValue
		inline double ClockDistance(double inValueA, double inValueB, double inWrapValue)
		{
			double distance = inValueA - inValueB;

			if (distance < 0) {
                double otherDir = inWrapValue + distance;
				return (-distance < otherDir) ? -distance : otherDir;
			}
			else {
                double otherDir = inWrapValue - distance;
				return (distance < otherDir) ? distance : otherDir;
			}
		}

		/// Calculates shortest distance between two reduced (within the first iteration of the interval) points on a looping interval [0, inWrapValue)
		///\param inValueA The first value (must be smaller than inWrapValue)
		///\param inValueB The second value (must be smaller than inWrapValue)
		///\param inWrapValue The maximum value (the minimum is always 0)
		///\return The distance between inValueA and inValueB on the circle 0 to inWrapValue
		inline float ClockDistance(float inValueA, float inValueB, float inWrapValue)
		{
			float distance = inValueA - inValueB;

			if (distance < 0) {
				float otherDir = inWrapValue + distance;
				return (-distance < otherDir) ? -distance : otherDir;
			}
			else {
				float otherDir = inWrapValue - distance;
				return (distance < otherDir) ? distance : otherDir;
			}
		}

		/// Calculates shortest distance between two reduced (within the first iteration of the interval) points on a looping interval [0, inNumberOfSlices)
		///\param inValueA The first value (must be smaller than inNumberOfSlices)
		///\param inValueB The second value (must be smaller than inNumberOfSlices)
		///\param inNumberOfSlices The maximum value (the minimum is always 0)
		///\return The distance between inValueA and inValueB on the circle 0 to inNumberOfSlices
		inline int ClockDistance(int inValueA, int inValueB, int inNumberOfSlices)
		{
			int distance = inValueA - inValueB;

			if (distance < 0) {
				int otherDir = inNumberOfSlices + distance;
				return (-distance < otherDir) ? -distance : otherDir;
			}
			else {
				int otherDir = inNumberOfSlices - distance;
				return (distance < otherDir) ? distance : otherDir;
			}
		}
	}
}