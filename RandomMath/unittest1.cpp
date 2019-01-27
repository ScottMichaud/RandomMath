#include "stdafx.h"
#include "CppUnitTest.h"
#include "RandomMath.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RandomMath
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(1, ClockDistance(1, 2, 12)); //1 and 2 are two apart on a 12-slice clock.
			Assert::AreEqual(2, ClockDistance(11, 1, 12)); //11 and 1 are 2 apart on a 12-slice clock.
			Assert::AreEqual(0, ClockDistance(12, 12, 12));
			Assert::AreEqual(0, ClockDistance(1, 1, 12));
			Assert::AreEqual(2, ClockDistance(1, 11, 12));
			Assert::AreEqual(0, ClockDistance(-1, 11, 12));
			Assert::AreEqual(0, ClockDistance(-1, -1, 10));
			Assert::AreEqual(200, ClockDistance(900, 100, 1000));
			Assert::AreEqual(2, ClockDistance(5, 7, 12));
			Assert::AreEqual(2, ClockDistance(7, 5, 12));
		}

	};
}