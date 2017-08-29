#include <iostream>
#include <fstream>
#include <memory>

#include "..\..\shared\ProblemEngine.h"

int FindSingleElement(const std::shared_ptr<int>& inputArray, int size);

int main(int argc, char * argv[])
{
	ProblemEngine engine("input.txt");
	if (!engine.IsFileOk())
	{
		std::cout << "Unable to open input.txt" << std::endl;
		return 1;
	}

	auto testCases = engine.LoadTestCases();

	for (const auto& testCase : testCases)
	{
		if (testCase.Size % 2 == 0) //only odd inputs accepted
			continue;

		auto singleElement = FindSingleElement(testCase.Data, testCase.Size);

		std::cout << singleElement << std::endl;
	}

	return 0;
}

int FindSingleElement(const std::shared_ptr<int>& inputArray, int size)
{
	return 0;
}