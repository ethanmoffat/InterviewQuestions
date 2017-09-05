#include <iostream>
#include <fstream>
#include <memory>

#include "list.h"
#include "ProblemEngine.h"

PNode SortList(PNode head);

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
		PNode head = CreateList(testCase.Datas.front(), testCase.Sizes.front());
		PNode newHead = SortList(head);

		PrintList(newHead);

		FreeList(newHead);
	}

	return 0;
}

PNode SortList(PNode head)
{
	const int NUM_VALUES = 3;
	int count[NUM_VALUES] = { 0 };
	PNode current = head;

	while (current != nullptr)
	{
		if (current->value < 0 || current->value >= NUM_VALUES)
			throw std::exception("Invalid list value");

		count[current->value]++;
		current = current->next;
	}

	current = head;
	for (int ndx = 0; ndx < NUM_VALUES; ++ndx)
	{
		for (int i = 0; i < count[ndx]; ++i)
		{
			current->value = ndx;
			current = current->next;
		}
	}

	return head;
}