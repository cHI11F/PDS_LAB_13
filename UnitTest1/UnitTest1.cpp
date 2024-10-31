#include "pch.h"
#include "CppUnitTest.h"
#include "../PDS_LAB_13/PDS_LAB_13.cpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestGreedyColoring)
		{
			vector<vector<int>> adjList = {
				{ 1, 2 },
				{ 0, 2, 3 },
				{ 0, 1, 3 },
				{ 1 }
			};


			vector<int> colors = greedyColoring(adjList);


			Assert::AreEqual(colors[0], 0);
			Assert::AreEqual(colors[1], 1);
			Assert::AreEqual(colors[1], 1);
			Assert::AreEqual(colors[3], 0);

			int maxColor = *max_element(colors.begin(), colors.end());
			Assert::AreEqual(maxColor + 1, 3);
		}
	};
}
