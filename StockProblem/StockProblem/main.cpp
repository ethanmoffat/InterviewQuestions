#include <iostream>
#include <fstream>
#include <list>
#include <memory>

struct BuySell
{
	int BuyIndex;
	int SellIndex;

	BuySell() : BuyIndex(0), SellIndex(0) { }
};

std::list<BuySell> FindBestDays(std::shared_ptr<int> inputStockPrices, int numberOfPrices);

int main(int argc, char * argv[])
{
	std::ifstream inputFile("input.txt");
	if (inputFile.bad() || inputFile.eof())
	{
		std::cout << "Unable to open input.txt" << std::endl;
		return 1;
	}

	int numberOfTestCases = 0;
	inputFile >> numberOfTestCases;

	for (int i = 0; i < numberOfTestCases; ++i)
	{
		int numberOfStockDays = 0;
		inputFile >> numberOfStockDays;

		std::shared_ptr<int> stocksForThisTestCase(new int[numberOfStockDays]);
		for (int j = 0; j < numberOfStockDays; ++j)
			inputFile >> stocksForThisTestCase.get()[j];

		auto buySellPairs = FindBestDays(stocksForThisTestCase, numberOfStockDays);
		if (buySellPairs.size() == 0)
			std::cout << "No Profit" << std::endl;

		for (const auto& buySell : buySellPairs)
			std::cout << "(" << buySell.BuyIndex << ", " << buySell.SellIndex << ") ";
	}

	inputFile.close();

	return 0;
}

std::list<BuySell> FindBestDays(std::shared_ptr<int> inputStockPrices, int numberOfPrices)
{
	std::list<BuySell> retList;

	for (int i = 0; i < numberOfPrices; ++i)
	{

	}

	return retList;
}