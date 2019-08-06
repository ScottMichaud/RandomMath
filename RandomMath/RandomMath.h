#pragma once

#include <algorithm>

namespace RandomMath
{
	struct InclusiveDouble { double boundaryToInclude; };
	struct InclusiveFloat { float boundaryToInclude; };
	struct InclusiveInt { int boundaryToInclude; };
	struct ExclusiveDouble { double boundaryToExclude; };
	struct ExclusiveFloat { float boundaryToExclude; };
	struct ExclusiveInt { int boundaryToExclude; };

	//IsBetween Double
	inline bool IsBetween(double inValue, InclusiveDouble inMin, InclusiveDouble inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue <= inMax.boundaryToInclude;
	}

	inline bool IsBetween(double inValue, InclusiveDouble inMin, ExclusiveDouble inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue < inMax.boundaryToExclude;
	}

	inline bool IsBetween(double inValue, ExclusiveDouble inMin, InclusiveDouble inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue <= inMax.boundaryToInclude;
	}

	inline bool IsBetween(double inValue, ExclusiveDouble inMin, ExclusiveDouble inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue < inMax.boundaryToExclude;
	}

	//IsBetween Float
	inline bool IsBetween(float inValue, InclusiveFloat inMin, InclusiveFloat inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue <= inMax.boundaryToInclude;
	}

	inline bool IsBetween(float inValue, InclusiveFloat inMin, ExclusiveFloat inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue < inMax.boundaryToExclude;
	}

	inline bool IsBetween(float inValue, ExclusiveFloat inMin, InclusiveFloat inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue <= inMax.boundaryToInclude;
	}

	inline bool IsBetween(float inValue, ExclusiveFloat inMin, ExclusiveFloat inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue < inMax.boundaryToExclude;
	}

	//IsBetween Int
	inline bool IsBetween(int inValue, InclusiveInt inMin, InclusiveInt inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue <= inMax.boundaryToInclude;
	}

	inline bool IsBetween(int inValue, InclusiveInt inMin, ExclusiveInt inMax)
	{
		return inValue >= inMin.boundaryToInclude && inValue < inMax.boundaryToExclude;
	}

	inline bool IsBetween(int inValue, ExclusiveInt inMin, InclusiveInt inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue <= inMax.boundaryToInclude;
	}

	inline bool IsBetween(int inValue, ExclusiveInt inMin, ExclusiveInt inMax)
	{
		return inValue > inMin.boundaryToExclude && inValue < inMax.boundaryToExclude;
	}

	//Clamp
	inline double Clamp(double inValue, double inMin, double inMax)
	{
		return std::min(std::max(inValue, inMin), inMax);
	}

	inline float Clamp(float inValue, float inMin, float inMax)
	{
		return std::min(std::max(inValue, inMin), inMax);
	}

	inline int Clamp(int inValue, int inMin, int inMax)
	{
		return std::min(std::max(inValue, inMin), inMax);
	}

	inline double PositiveModulo(double inValue, double inWrapValue)
	{
		return std::fmod((std::fmod(inValue, inWrapValue) + inWrapValue), inWrapValue);
	}

	inline float PositiveModulo(float inValue, float inWrapValue)
	{
		return std::fmod((std::fmod(inValue, inWrapValue) + inWrapValue), inWrapValue);
	}

	inline int PositiveModulo(int inValue, int inNumberOfSlices)
	{
		return ((inValue % inNumberOfSlices) + inNumberOfSlices) % inNumberOfSlices;
	}

	double ClockDistance(double inValueA, double inValueB, double inWrapValue);
	float ClockDistance(float inValueA, float inValueB, float inWrapValue);
	int ClockDistance(int inValueA, int inValueB, int inNumberOfSlice);
}