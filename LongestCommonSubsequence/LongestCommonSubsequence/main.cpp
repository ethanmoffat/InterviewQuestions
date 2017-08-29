#include <iostream>
#include <fstream>
#include <memory>
#include <string>

#include "..\..\shared\ProblemEngine.h"

//build properly terminated string out of raw character pointer
std::string BuildString(char * ptr, int numElements)
{
	std::string ret = "";
	for (int i = 0; i < numElements; ++i)
		ret += ptr[i];
	return ret;
}

std::string LongestCommonSubsequence(const std::string& str1, const std::string& str2);

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
		auto string1 = BuildString(testCase.Datas.front().get(), testCase.Sizes.front());
		auto string2 = BuildString(testCase.Datas.back().get(), testCase.Sizes.back());
		auto longestCommonSubsequence = LongestCommonSubsequence(string1, string2);
		std::cout << longestCommonSubsequence.size() << std::endl;
	}

	return 0;
}

std::string LongestCommonSubsequence(const std::string& str1, const std::string& str2)
{
	return "";
}