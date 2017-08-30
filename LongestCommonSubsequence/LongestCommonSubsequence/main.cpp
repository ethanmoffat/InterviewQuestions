#include <iostream>
#include <fstream>
#include <memory>
#include <string>
#include <map>
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

typedef std::map<int, std::map<int, std::string>> LcsMap;

std::string LongestCommonSubsequence(const std::string& str1, const std::string& str2);
std::string LongestCommonSubsequenceDynamic(const std::string& str1, const std::string& str2, LcsMap &map);
std::string LCSIterativeDynamic(const std::string& str1, const std::string& str2);

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

		auto start = clock();
		auto lcs = LongestCommonSubsequence(string1, string2);
		auto lcsTime = double(clock() - start) / CLOCKS_PER_SEC;

		LcsMap map;
		start = clock();
		auto lcsDynamic = LongestCommonSubsequenceDynamic(string1, string2, map);
		auto lcsDynamicTime = double(clock() - start) / CLOCKS_PER_SEC;

		std::cout << lcs.size() << ": " << lcs << " (" << lcsTime << ")" << std::endl;
		std::cout << lcsDynamic.size() << ": " << lcsDynamic << " (" << lcsDynamicTime << ")" << std::endl;

		start = clock();
		auto lcsIterativeDynamic = LCSIterativeDynamic(string1, string2);
		auto lcsIterativeDynamicTime = double(clock() - start) / CLOCKS_PER_SEC;
		std::cout << lcsIterativeDynamic.size() << ": " << lcsIterativeDynamic << " (" << lcsIterativeDynamicTime << ")" << std::endl;
	}

	return 0;
}

std::string LongestCommonSubsequence(const std::string& str1, const std::string& str2)
{
	if (str1.empty() || str2.empty())
		return "";

	auto str1NewSize = str1.size() - 1;
	auto str2NewSize = str2.size() - 1;
	auto firstSubStr = str1.substr(0, str1NewSize);
	auto secondSubStr = str2.substr(0, str2NewSize);

	if (str1.back() == str2.back())
		return LongestCommonSubsequence(firstSubStr, secondSubStr) + str1.back();

	auto first = LongestCommonSubsequence(firstSubStr, str2);
	auto second = LongestCommonSubsequence(str1, secondSubStr);

	return first.length() > second.length() ? first : second;
}

std::string LongestCommonSubsequenceDynamic(const std::string& str1, const std::string& str2, LcsMap &map)
{
	if (str1.empty() || str2.empty())
		return "";

	auto str1NewSize = str1.size() - 1;
	auto str2NewSize = str2.size() - 1;
	auto firstSubStr = str1.substr(0, str1NewSize);
	auto secondSubStr = str2.substr(0, str2NewSize);

	if (str1.back() == str2.back())
	{
		if (map.find(str1NewSize) == map.end() || map[str1NewSize].find(str2NewSize) == map[str1NewSize].end())
			map[str1NewSize][str2NewSize] = LongestCommonSubsequenceDynamic(firstSubStr, secondSubStr, map);
		return map[str1NewSize][str2NewSize] + str1.back();
	}

	if (map.find(str1NewSize) == map.end() || map[str1NewSize].find(str2.size()) == map[str1NewSize].end())
		map[str1NewSize][str2.size()] = LongestCommonSubsequenceDynamic(firstSubStr, str2, map);
	if (map.find(str1.size()) == map.end() || map[str1.size()].find(str2NewSize) == map[str1.size()].end())
		map[str1.size()][str2NewSize] = LongestCommonSubsequenceDynamic(str1, secondSubStr, map);

	auto first = map[str1NewSize][str2.size()];
	auto second = map[str1.size()][str2NewSize];

	return first.length() > second.length() ? first : second;
}

std::string LCSIterativeDynamic(const std::string& str1, const std::string& str2)
{
	LcsMap map;

	for (int i = 0; i < str1.length(); ++i)
	{
		for (int j = 0; j < str2.length(); ++j)
		{
			if (str1[i] == str2[j])
				map[i+1][j+1] = map[i][j] + str1[i];
			else
			{
				auto first = map[i][j+1];
				auto second = map[i+1][j];

				map[i+1][j+1] = first.length() > second.length() ? first : second;
			}
		}
	}

	return map[str1.length()][str2.length()];
}