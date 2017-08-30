#include <iostream>
#include <ctime>

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

		auto start = clock();
		auto editDistance = EditDistance(firstString, secondString);
		auto time = double(clock() - start) / CLOCKS_PER_SEC;

		std::cout << editDistance << " (" << time << ")" << std::endl;
	}

	return 0;
}

int EditDistance(const std::string& one, const std::string& two)
{
	if (one.empty())
		return two.size();
	if (two.empty())
		return one.size();

	auto newOne = one.substr(0, one.size() - 1);
	auto newTwo = two.substr(0, two.size() - 1);

	if (one.back() == two.back())
		return EditDistance(newOne, newTwo);

	return 1 + min(min(
		EditDistance(newOne, two),
		EditDistance(one, newTwo)),
		EditDistance(newOne, newTwo)
	);
}