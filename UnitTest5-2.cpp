#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Софія\source\repos\lab5-2\lab5-2\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest52
{
	TEST_CLASS(UnitTest52)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a = D3(3, 3, 3, 0, 0);
			Assert::AreEqual(a, 3.0);
		}
	};
}
