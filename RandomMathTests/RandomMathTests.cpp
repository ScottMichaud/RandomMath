#include "CppUnitTest.h"
#include "RandomMath.h"

#include <limits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace RandomMathWIP;

namespace RandomMathTests
{
	TEST_CLASS(ClockDistanceTests)
	{
	public:

		TEST_METHOD(IntTests)
		{
			Assert::AreEqual(1, ClockDistance(1, 2, 12)); //1 and 2 are one apart on a 12-slice clock.
			Assert::AreEqual(2, ClockDistance(11, 1, 12)); //11 and 1 are two apart on a 12-slice clock.
			Assert::AreEqual(0, ClockDistance(12, 12, 12));
			Assert::AreEqual(0, ClockDistance(1, 1, 12));
			Assert::AreEqual(2, ClockDistance(1, 11, 12));
			Assert::AreEqual(0, ClockDistance(-1, 11, 12));
			Assert::AreEqual(0, ClockDistance(-1, -1, 10));
			Assert::AreEqual(200, ClockDistance(900, 100, 1000));
			Assert::AreEqual(2, ClockDistance(5, 7, 12));
			Assert::AreEqual(2, ClockDistance(7, 5, 12));
		}

		TEST_METHOD(InRangeIntTests)
		{
			Assert::AreEqual(1, Reduced::ClockDistance(1, 2, 12)); //1 and 2 are one apart on a 12-slice clock.
			Assert::AreEqual(2, Reduced::ClockDistance(11, 1, 12)); //11 and 1 are two apart on a 12-slice clock.
			Assert::AreEqual(0, Reduced::ClockDistance(1, 1, 12));
			Assert::AreEqual(2, Reduced::ClockDistance(1, 11, 12));
			Assert::AreEqual(200, Reduced::ClockDistance(900, 100, 1000));
			Assert::AreEqual(2, Reduced::ClockDistance(5, 7, 12));
			Assert::AreEqual(2, Reduced::ClockDistance(7, 5, 12));
		}

		TEST_METHOD(FloatTests)
		{
			Assert::AreEqual(1.0f, ClockDistance(1.0f, 2.0f, 12.0f)); //1 and 2 are one apart on a 12-slice clock.
			Assert::AreEqual(2.0f, ClockDistance(11.0f, 1.0f, 12.0f)); //11 and 1 are two apart on a 12-slice clock.
			Assert::AreEqual(0.0f, ClockDistance(12.0f, 12.0f, 12.0f));
			Assert::AreEqual(0.0f, ClockDistance(1.0f, 1.0f, 12.0f));
			Assert::AreEqual(2.0f, ClockDistance(1.0f, 11.0f, 12.0f));
			Assert::AreEqual(0.0f, ClockDistance(-1.0f, 11.0f, 12.0f));
			Assert::AreEqual(0.0f, ClockDistance(-1.0f, -1.0f, 10.0f));
			Assert::AreEqual(200.0f, ClockDistance(900.0f, 100.0f, 1000.0f));
			Assert::AreEqual(2.0f, ClockDistance(5.0f, 7.0f, 12.0f));
			Assert::AreEqual(2.0f, ClockDistance(7.0f, 5.0f, 12.0f));
		}

		TEST_METHOD(InRangeFloatTests)
		{
			Assert::AreEqual(1.0f, Reduced::ClockDistance(1.0f, 2.0f, 12.0f)); //1 and 2 are one apart on a 12-slice clock.
			Assert::AreEqual(2.0f, Reduced::ClockDistance(11.0f, 1.0f, 12.0f)); //11 and 1 are two apart on a 12-slice clock.
			Assert::AreEqual(0.0f, Reduced::ClockDistance(1.0f, 1.0f, 12.0f));
			Assert::AreEqual(2.0f, Reduced::ClockDistance(1.0f, 11.0f, 12.0f));
			Assert::AreEqual(200.0f, Reduced::ClockDistance(900.0f, 100.0f, 1000.0f));
			Assert::AreEqual(2.0f, Reduced::ClockDistance(5.0f, 7.0f, 12.0f));
			Assert::AreEqual(2.0f, Reduced::ClockDistance(7.0f, 5.0f, 12.0f));
		}

		TEST_METHOD(DoubleTests)
		{
			Assert::AreEqual(1.0, ClockDistance(1.0, 2.0, 12.0)); //1 and 2 are one apart on a 12-slice clock.
			Assert::AreEqual(2.0, ClockDistance(11.0, 1.0, 12.0)); //11 and 1 are two apart on a 12-slice clock.
			Assert::AreEqual(0.0, ClockDistance(12.0, 12.0, 12.0));
			Assert::AreEqual(0.0, ClockDistance(1.0, 1.0, 12.0));
			Assert::AreEqual(2.0, ClockDistance(1.0, 11.0, 12.0));
			Assert::AreEqual(0.0, ClockDistance(-1.0, 11.0, 12.0));
			Assert::AreEqual(0.0, ClockDistance(-1.0, -1.0, 10.0));
			Assert::AreEqual(200.0, ClockDistance(900.0, 100.0, 1000.0));
			Assert::AreEqual(2.0, ClockDistance(5.0, 7.0, 12.0));
			Assert::AreEqual(2.0, ClockDistance(7.0, 5.0, 12.0));
		}

		TEST_METHOD(InRangeDoubleTests)
		{
			Assert::AreEqual(1.0, Reduced::ClockDistance(1.0, 2.0, 12.0)); //1 and 2 are one apart on a 12-slice clock.
			Assert::AreEqual(2.0, Reduced::ClockDistance(11.0, 1.0, 12.0)); //11 and 1 are two apart on a 12-slice clock.
			Assert::AreEqual(0.0, Reduced::ClockDistance(1.0, 1.0, 12.0));
			Assert::AreEqual(2.0, Reduced::ClockDistance(1.0, 11.0, 12.0));
			Assert::AreEqual(200.0, Reduced::ClockDistance(900.0, 100.0, 1000.0));
			Assert::AreEqual(2.0, Reduced::ClockDistance(5.0, 7.0, 12.0));
			Assert::AreEqual(2.0, Reduced::ClockDistance(7.0, 5.0, 12.0));
		}
	};

	TEST_CLASS(PositiveModuloTests)
	{
	public:
		TEST_METHOD(IntTests)
		{
			Assert::AreEqual(1, PositiveModulo(11, 10));
			Assert::AreEqual(9, PositiveModulo(9, 10));
			Assert::AreEqual(1, PositiveModulo(-9, 10));
			Assert::AreEqual(9, PositiveModulo(-1, 10));
			Assert::AreEqual(0, PositiveModulo(0, 9));
		}

		TEST_METHOD(FloatTests)
		{
			Assert::AreEqual(1.0f, PositiveModulo(11.0f, 10.0f));
			Assert::AreEqual(9.0f, PositiveModulo(9.0f, 10.0f));
			Assert::AreEqual(1.0f, PositiveModulo(-9.0f, 10.0f));
			Assert::AreEqual(9.0f, PositiveModulo(-1.0f, 10.0f));
			Assert::AreEqual(0.0f, PositiveModulo(0.0f, 9.0f));
		}

		TEST_METHOD(DoubleTests)
		{
			Assert::AreEqual(1.0, PositiveModulo(11.0, 10.0));
			Assert::AreEqual(9.0, PositiveModulo(9.0, 10.0));
			Assert::AreEqual(1.0, PositiveModulo(-9.0, 10.0));
			Assert::AreEqual(9.0, PositiveModulo(-1.0, 10.0));
			Assert::AreEqual(0.0, PositiveModulo(0.0, 9.0));
		}
	};

	TEST_CLASS(IsBetweenTests)
	{
	public:
		/*TEST_METHOD(DoubleTests)
		{
			Assert::AreEqual(true, IsBetween(2.0, InclusiveDouble{ 2.0 }, ExclusiveDouble{ 3.0 }));
			Assert::AreEqual(false, IsBetween(3.0, InclusiveDouble{ 2.0 }, ExclusiveDouble{ 3.0 }));
			Assert::AreEqual(false, IsBetween(2.0, ExclusiveDouble{ 2.0 }, InclusiveDouble{ 3.0 }));
			Assert::AreEqual(true, IsBetween(3.0, ExclusiveDouble{ 2.0 }, InclusiveDouble{ 3.0 }));

			Assert::AreEqual(true, IsBetween(-2.0, InclusiveDouble{ -2.0 }, ExclusiveDouble{ -1.0 }));
			Assert::AreEqual(false, IsBetween(-1.0, InclusiveDouble{ -2.0 }, ExclusiveDouble{ -1.0 }));
			Assert::AreEqual(false, IsBetween(-2.0, ExclusiveDouble{ -2.0 }, InclusiveDouble{ -1.0 }));
			Assert::AreEqual(true, IsBetween(-1.0, ExclusiveDouble{ -2.0 }, InclusiveDouble{ -1.0 }));
		}

		TEST_METHOD(FloatTests)
		{
			Assert::AreEqual(true, IsBetween(2.0f, InclusiveFloat{ 2.0f }, ExclusiveFloat{ 3.0f }));
			Assert::AreEqual(false, IsBetween(3.0f, InclusiveFloat{ 2.0f }, ExclusiveFloat{ 3.0f }));
			Assert::AreEqual(false, IsBetween(2.0f, ExclusiveFloat{ 2.0f }, InclusiveFloat{ 3.0f }));
			Assert::AreEqual(true, IsBetween(3.0f, ExclusiveFloat{ 2.0f }, InclusiveFloat{ 3.0f }));

			Assert::AreEqual(true, IsBetween(-2.0f, InclusiveFloat{ -2.0f }, ExclusiveFloat{ -1.0f }));
			Assert::AreEqual(false, IsBetween(-1.0f, InclusiveFloat{ -2.0f }, ExclusiveFloat{ -1.0f }));
			Assert::AreEqual(false, IsBetween(-2.0f, ExclusiveFloat{ -2.0f }, InclusiveFloat{ -1.0f }));
			Assert::AreEqual(true, IsBetween(-1.0f, ExclusiveFloat{ -2.0f }, InclusiveFloat{ -1.0f }));
		}

		TEST_METHOD(IntTests)
		{
			Assert::AreEqual(true, IsBetween(2, InclusiveInt{ 2 }, ExclusiveInt{ 3 }));
			Assert::AreEqual(false, IsBetween(3, InclusiveInt{ 2 }, ExclusiveInt{ 3 }));
			Assert::AreEqual(false, IsBetween(2, ExclusiveInt{ 2 }, InclusiveInt{ 3 }));
			Assert::AreEqual(true, IsBetween(3, ExclusiveInt{ 2 }, InclusiveInt{ 3 }));

			Assert::AreEqual(true, IsBetween(-2, InclusiveInt{ -2 }, ExclusiveInt{ -1 }));
			Assert::AreEqual(false, IsBetween(-1, InclusiveInt{ -2 }, ExclusiveInt{ -1 }));
			Assert::AreEqual(false, IsBetween(-2, ExclusiveInt{ -2 }, InclusiveInt{ -1 }));
			Assert::AreEqual(true, IsBetween(-1, ExclusiveInt{ -2 }, InclusiveInt{ -1 }));
		}*/
	};

	TEST_CLASS(IsIntegerTests)
	{
		TEST_METHOD(DoubleTests)
		{
			Assert::AreEqual(true, IsInteger(2.0));
			Assert::AreEqual(false, IsInteger(2.00001));
			Assert::AreEqual(true, IsInteger(-2.0));
			Assert::AreEqual(false, IsInteger(-2.00001));
			Assert::AreEqual(true, IsInteger(0.0));
			Assert::AreEqual(true, IsInteger(-0.0));
			Assert::AreEqual(false, IsInteger(std::numeric_limits<double>::quiet_NaN() * 0.0));
			Assert::AreEqual(true, IsInteger((double)std::numeric_limits<int>::max()));
			Assert::AreEqual(true, IsInteger((double)std::numeric_limits<long long int>::max()));
			Assert::AreEqual(true, IsInteger((double)std::numeric_limits<int>::max()));
			Assert::AreEqual(true, IsInteger((double)std::numeric_limits<long long int>::max()));
		}

		TEST_METHOD(FloatTests)
		{
			Assert::AreEqual(true, IsInteger(2.0f));
			Assert::AreEqual(false, IsInteger(2.00001f));
			Assert::AreEqual(true, IsInteger(-2.0f));
			Assert::AreEqual(false, IsInteger(-2.00001f));
			Assert::AreEqual(true, IsInteger(0.0f));
			Assert::AreEqual(true, IsInteger(-0.0f));
			Assert::AreEqual(false, IsInteger(std::numeric_limits<float>::quiet_NaN() * 0.0f));
			Assert::AreEqual(true, IsInteger((float)std::numeric_limits<int>::max()));
			Assert::AreEqual(true, IsInteger((float)std::numeric_limits<long long int>::max()));
			Assert::AreEqual(true, IsInteger(-(float)std::numeric_limits<int>::max()));
			Assert::AreEqual(true, IsInteger(-(float)std::numeric_limits<long long int>::max()));
		}
	};

	TEST_CLASS(IsEvenTests)
	{
		TEST_METHOD(DoubleTests)
		{
			Assert::AreEqual(true, IsEven(2.0));
			Assert::AreEqual(true, IsEven(-2.0));
			Assert::AreEqual(true, IsEven(0.0));
			Assert::AreEqual(false, IsEven(1.0));
			Assert::AreEqual(false, IsEven(-1.0));
			Assert::AreEqual(false, IsEven(2.5));
			Assert::AreEqual(false, IsEven(-2.5));
			// Double has enough precision to realize that int_max is odd.
			Assert::AreEqual(false, IsEven((double)(std::numeric_limits<int>::max())));
			Assert::AreEqual(true, IsEven((double)(std::numeric_limits<int>::max()) + 1));
			Assert::AreEqual(false, IsEven((double)(-std::numeric_limits<int>::max())));
			Assert::AreEqual(true, IsEven((double)(-std::numeric_limits<int>::max()) - 1));
			Assert::AreEqual(false, IsEven((double)(-std::numeric_limits<int>::max()) - 2));
		}

		TEST_METHOD(FloatTests)
		{
			Assert::AreEqual(true, IsEven(2.0f));
			Assert::AreEqual(true, IsEven(-2.0f));
			Assert::AreEqual(true, IsEven(0.0f));
			Assert::AreEqual(false, IsEven(1.0f));
			Assert::AreEqual(false, IsEven(-1.0f));
			Assert::AreEqual(false, IsEven(2.5f));
			Assert::AreEqual(false, IsEven(-2.5f));
			// Float doesn't have enough precision to recognize int_max is odd, but knows it's an integer.
			Assert::AreEqual(true, IsEven((float)(std::numeric_limits<int>::max()) + 1));
		}

		TEST_METHOD(IntTests)
		{
			Assert::AreEqual(true, IsEven(2));
			Assert::AreEqual(true, IsEven(-2));
			Assert::AreEqual(true, IsEven(0));
			Assert::AreEqual(false, IsEven(1));
			Assert::AreEqual(false, IsEven(-1));
		}
	};

	TEST_CLASS(IsOddTests)
	{
		TEST_METHOD(DoubleTests)
		{
			Assert::AreEqual(false, IsOdd(2.0));
			Assert::AreEqual(false, IsOdd(-2.0));
			Assert::AreEqual(false, IsOdd(0.0));
			Assert::AreEqual(true, IsOdd(1.0));
			Assert::AreEqual(true, IsOdd(-1.0));
			Assert::AreEqual(false, IsOdd(2.5));
			Assert::AreEqual(false, IsOdd(-2.5));
			Assert::AreEqual(true, IsOdd((double)(std::numeric_limits<int>::max())));
			Assert::AreEqual(false, IsOdd((double)(std::numeric_limits<int>::max()) + 1));
			Assert::AreEqual(true, IsOdd((double)(-std::numeric_limits<int>::max())));
			Assert::AreEqual(false, IsOdd((double)(-std::numeric_limits<int>::max()) - 1));
			Assert::AreEqual(true, IsOdd((double)(-std::numeric_limits<int>::max()) - 2));
		}

		TEST_METHOD(FloatTests)
		{
			Assert::AreEqual(false, IsOdd(2.0f));
			Assert::AreEqual(false, IsOdd(-2.0f));
			Assert::AreEqual(false, IsOdd(0.0f));
			Assert::AreEqual(true, IsOdd(1.0f));
			Assert::AreEqual(true, IsOdd(-1.0f));
			Assert::AreEqual(false, IsOdd(2.5f));
			Assert::AreEqual(false, IsOdd(-2.5f));
		}

		TEST_METHOD(IntTests)
		{
			Assert::AreEqual(false, IsOdd(2));
			Assert::AreEqual(false, IsOdd(-2));
			Assert::AreEqual(false, IsOdd(0));
			Assert::AreEqual(true, IsOdd(1));
			Assert::AreEqual(true, IsOdd(-1));
		}
	};

	TEST_CLASS(LerpTests)
	{
		TEST_METHOD(DoubleTests)
		{
			Assert::AreEqual(0.67, Lerp(0.67, 2.63, 0.0)); //At start, imprecise min and max (tests for round error on bounds)
			Assert::AreEqual(2.63, Lerp(0.67, 2.63, 1.0)); //At end, imprecise min and max (tests for round error on bounds)
			Assert::AreEqual(1.0, Lerp(0.5, 1.5, 0.5));
			Assert::AreEqual(-1.0, Lerp(-1.5, -0.5, 0.5));
		}

		TEST_METHOD(FloatTests)
		{
			Assert::AreEqual(0.67f, Lerp(0.67f, 2.63f, 0.0f)); //At start, imprecise min and max (tests for round error on bounds)
			Assert::AreEqual(2.63f, Lerp(0.67f, 2.63f, 1.0f)); //At end, imprecise min and max (tests for round error on bounds)
			Assert::AreEqual(1.0f, Lerp(0.5f, 1.5f, 0.5f));
			Assert::AreEqual(-1.0f, Lerp(-1.5f, -0.5f, 0.5f));
		}
	};

	TEST_CLASS(ClampTests)
	{
		TEST_METHOD(DoubleTests)
		{
			Assert::AreEqual(-1.0, Clamp(-10.0, -1.0, 1.0));
			Assert::AreEqual(1.0, Clamp(10.0, -1.0, 1.0));
			Assert::AreEqual(-1.0, Clamp(-1.0, -1.0, 1.0));
			Assert::AreEqual(1.0, Clamp(1.0, -1.0, 1.0));
			Assert::AreEqual(0.0, Clamp(0.0, -1.0, 1.0));
			Assert::AreEqual(0.25, Clamp(0.25, -1.0, 1.0));
			Assert::AreEqual(-0.25, Clamp(-0.25, -1.0, 1.0));
			Assert::AreEqual(1.0, Clamp(10.0, -1.0, 1.0));

			Assert::AreEqual(-20.0, Clamp(-30.0, -20.0, 2.0));
			Assert::AreEqual(2.0, Clamp(30.0, -20.0, 2.0));
			Assert::AreEqual(-10.5, Clamp(-10.5, -10.5, 10.5));
			Assert::AreEqual(10.5, Clamp(10.5, -10.5, 10.5));
			Assert::AreEqual(0.0, Clamp(0.0, 0.0, 0.0));
		}

		TEST_METHOD(FloatTests)
		{
			Assert::AreEqual(-1.0f, Clamp(-10.0f, -1.0f, 1.0f));
			Assert::AreEqual(1.0f, Clamp(10.0f, -1.0f, 1.0f));
			Assert::AreEqual(-1.0f, Clamp(-1.0f, -1.0f, 1.0f));
			Assert::AreEqual(1.0f, Clamp(1.0f, -1.0f, 1.0f));
			Assert::AreEqual(0.0f, Clamp(0.0f, -1.0f, 1.0f));
			Assert::AreEqual(0.25f, Clamp(0.25f, -1.0f, 1.0f));
			Assert::AreEqual(-0.25f, Clamp(-0.25f, -1.0f, 1.0f));
			Assert::AreEqual(1.0f, Clamp(10.0f, -1.0f, 1.0f));

			Assert::AreEqual(-20.0f, Clamp(-30.0f, -20.0f, 2.0f));
			Assert::AreEqual(2.0f, Clamp(30.0f, -20.0f, 2.0f));
			Assert::AreEqual(-10.5f, Clamp(-10.5f, -10.5f, 10.5f));
			Assert::AreEqual(10.5f, Clamp(10.5f, -10.5f, 10.5f));
			Assert::AreEqual(0.0f, Clamp(0.0f, 0.0f, 0.0f));
		}

		TEST_METHOD(IntTests)
		{
			Assert::AreEqual(-1, Clamp(-10, -1, 1));
			Assert::AreEqual(1, Clamp(10, -1, 1));
			Assert::AreEqual(-1, Clamp(-1, -1, 1));
			Assert::AreEqual(1, Clamp(1, -1, 1));
			Assert::AreEqual(0, Clamp(0, -1, 1));
			Assert::AreEqual(1, Clamp(10, -1, 1));

			Assert::AreEqual(-20, Clamp(-30, -20, 2));
			Assert::AreEqual(2, Clamp(30, -20, 2));
			Assert::AreEqual(0, Clamp(0, 0, 0));
		}
	};
}