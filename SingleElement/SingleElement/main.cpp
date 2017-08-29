#include <iostream>
#include <fstream>
#include <memory>

#include "..\..\shared\ProblemEngine.h"

int FindSingleElement(const std::shared_ptr<int>& inputArray, int size);

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
		if (testCase.Sizes.front() % 2 == 0) //only odd inputs accepted
			continue;

		auto singleElement = FindSingleElement(testCase.Datas.front(), testCase.Sizes.front());

		std::cout << singleElement << std::endl;
	}

	return 0;
}

int FindSingleElement(const std::shared_ptr<int>& inputArray, int size)
{
	const int INT_SIZE_IN_BITS = 32;

	//this method only works if there are 'n' occurrences of each element other than the single element
	//in the case of this test data, there are two occurrences of every other element since the problem states pairs of people
	const int EXPECTED_ELEMENT_OCCURRENCES = 2;

	int result = 0;
	auto ptr = inputArray.get();

	for (int bit = 0; bit < INT_SIZE_IN_BITS; ++bit)
	{
		int sum = 0;
		int bitMask = 1 << bit;

		for (int i = 0; i < size; ++i)
			if (ptr[i] & bitMask)
				sum++;

		if (sum % EXPECTED_ELEMENT_OCCURRENCES != 0)
			result |= bitMask;
	}

	return result;
}