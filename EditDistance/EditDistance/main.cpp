#include <iostream>

#include "..\..\shared\ProblemEngine.h"

//build properly terminated string out of raw character pointer
std::string BuildString(char * ptr, int numElements)
{
	std::string ret = "";
	for (int i = 0; i < numElements; ++i)
		ret += ptr[i];
	return ret;
}

size_t min(size_t a, size_t b)
{
	return a < b ? a : b;
}

int EditDistance(const std::string& one, const std::string& two);

int main(int argc, char * argv[])
{
	ProblemEngine<char> engine("input.txt");
	if (!engine.IsFileOk())
	{
		std::cout << "Unable to open input.txt" << std::endl;
		return 1;
	}

	auto testCases = engine.LoadTestCases(2);

	for (const auto& testCase : testCases)
	{
		auto firstString = BuildString(testCase.Datas.front().get(), testCase.Sizes.front());
		auto secondString = BuildString(testCase.Datas.back().get(), testCase.Sizes.back());

		auto editDistance = EditDistance(firstString, secondString);

		std::cout << editDistance << std::endl;
	}

	return 0;
}

int EditDistance(const std::string& one, const std::string& two)
{
	return 0;
}