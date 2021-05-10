#include "pch.h"
#include "CppUnitTest.h"
#include "../6.7/6.7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest67
{
	TEST_CLASS(UnitTest67)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Array a = { new int[3]{ 9, 8, 1 }, 3 };
			Array b = { new int[3]{ 8, 9, 0}, 3 };
			Array r = Merge_if(a, b);
			Assert::AreEqual(*(r.start), 9);
		}
	};
}
