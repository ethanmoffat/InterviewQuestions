#include <iostream>
#include <fstream>
#include <list>

#include "..\..\shared\ProblemEngine.h"

struct BuySell
{
	int BuyIndex;
	int SellIndex;

	BuySell() : BuyIndex(0), SellIndex(0) { }
	BuySell(int buy, int sell) : BuyIndex(buy), SellIndex(sell) { }
};

std::list<BuySell> FindBestDays(std::shared_ptr<int> inputStockPrices, int numberOfPrices);

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
		auto buySellPairs = FindBestDays(testCase.Data, testCase.Size);
		if (buySellPairs.size() == 0)
			std::cout << "No Profit";

		for (const auto& buySell : buySellPairs)
			std::cout << "(" << buySell.BuyIndex << " " << buySell.SellIndex << ") ";

		std::cout << std::endl;
	}

	return 0;
}

std::list<BuySell> FindBestDays(std::shared_ptr<int> inputStockPrices, int numberOfPrices)
{
	std::list<BuySell> retList;

	if (numberOfPrices < 2)
		return retList;

	auto localMin = 0;
	auto localMax = 0;
	auto ptr = inputStockPrices.get();

	for (int i = 1; i < numberOfPrices; ++i)
	{
		if (ptr[i] < ptr[localMax])
		{
			if (localMax - localMin > 0)
				retList.push_back(BuySell(localMin, localMax));
			localMin = localMax = i;
		}
		else if (ptr[i] > ptr[localMax])
			localMax = i;

		if (ptr[i] < ptr[localMin])
			localMin = i;
	}

	if (localMax - localMin > 0)
		retList.push_back(BuySell(localMin, localMax));

	return retList;
}