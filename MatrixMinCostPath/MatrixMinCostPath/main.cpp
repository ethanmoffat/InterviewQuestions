#include <iostream>

#include "..\..\shared\ProblemEngine.h"

int FindShortestPath(const int * const data, int size);

int main(int argc, char * argv[])
{
	ProblemEngine<> engine("input.txt");
	if (!engine.IsFileOk())
	{
		std::cout << "Unable to open input.txt" << std::endl;
		return 1;
	}

	auto testCases = engine.LoadTestCases();

	for (const auto& testCase : testCases)
	{
		auto data = testCase.Datas.front().get();
		auto size = testCase.Sizes.front();

		auto sp = FindShortestPath(data, size);

		std::cout << sp << std::endl;
	}

	return 0;
}

int FindShortestPath(const int * const data, int size)
{
	return 0;
}