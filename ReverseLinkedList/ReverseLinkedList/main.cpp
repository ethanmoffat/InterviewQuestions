#include <iostream>
#include <fstream>
#include <memory>

#include "list.h"

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
		int numberOfListItems = 0;
		inputFile >> numberOfListItems;

		std::shared_ptr<int> listItemsForThisTestCase(new int[numberOfListItems]);
		for (int j = 0; j < numberOfListItems; ++j)
			inputFile >> listItemsForThisTestCase.get()[j];

		PNode head = CreateList(listItemsForThisTestCase, numberOfListItems);
		PNode newHead = ReverseList(head);

		PrintList(newHead);

		FreeList(newHead);
	}

	inputFile.close();

	return 0;
}