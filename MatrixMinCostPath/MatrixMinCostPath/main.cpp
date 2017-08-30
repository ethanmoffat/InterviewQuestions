#include <iostream>

#include "..\..\shared\ProblemEngine.h"

int FindShortestPath(int ** data, int rowSize);

int** CreateMatrix(const int * const input, int rowSize)
{
	auto ret = new int*[rowSize];
	for (int i = 0; i < rowSize; ++i)
	{
		ret[i] = new int[rowSize];
		for (int j = 0; j < rowSize; ++j)
			ret[i][j] = input == nullptr ? 0 : input[i * rowSize + j];
	}
	return ret;
}

void DeleteMatrix(int **& input, int rowSize)
{
	for (int i = 0; i < rowSize; ++i)
		delete[] input[i];
	delete[] input;
	input = nullptr;
}

int min(int a, int b, int c)
{
	if (a < b && a < c) return a;
	if (b < a && b < c) return b;
	return c;
}

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

		auto rowSize = static_cast<int>(sqrt(size));
		if (size != rowSize * rowSize)
			throw std::exception("input data is not a square matrix");

		int ** matrix = CreateMatrix(data, rowSize);
		auto sp = FindShortestPath(matrix, rowSize);
		DeleteMatrix(matrix, rowSize);

		std::cout << sp << std::endl;
	}

	return 0;
}

int FindShortestPath(int ** ptr, int rowSize)
{
	return 0;
}