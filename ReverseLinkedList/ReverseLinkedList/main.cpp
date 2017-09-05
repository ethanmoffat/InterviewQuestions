#include <iostream>
#include <fstream>
#include <memory>

#include "list.h"
#include "ProblemEngine.h"

PNode ReverseList(PNode head);

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		std::cout << "No input file specified." << std::endl;
		return 1;
	}

	ProblemEngine<> engine(argv[1]);
	if (!engine.IsFileOk())
	{
		std::cout << "Unable to open " << argv[1] << std::endl;
		return 1;
	}

	auto testCases = engine.LoadTestCases();

	for (const auto& testCase : testCases)
	{
		PNode head = CreateList(testCase.Datas.front(), testCase.Sizes.front());
		PNode newHead = ReverseList(head);

		PrintList(newHead);

		FreeList(newHead);
	}

	return 0;
}

PNode ReverseList(PNode head)
{
	if (head == nullptr || head->next == nullptr)
		return head;

	PNode current = head;
	PNode previous = nullptr;

	while (current != nullptr)
	{
		PNode temp = current;
		current = current->next;

		temp->next = previous;

		previous = temp;
	}

	return previous;
}