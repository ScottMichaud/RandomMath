#pragma once

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

	double ClockDistance(double inValueA, double inValueB, double inWrapValue);
	float ClockDistance(float inValueA, float inValueB, float inWrapValue);
	int ClockDistance(int inValueA, int inValueB, int inNumberOfSlice);
	double PositiveModulo(double inValue, double inNumberOfSlices);
	float PositiveModulo(float inValue, float inNumberOfSlices);
	int PositiveModulo(int inValue, int inNumberOfSlices);
}