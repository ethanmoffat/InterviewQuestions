#include <iostream>
#include <fstream>
#include <memory>

#include "..\..\shared\list.h"
#include "..\..\shared\ProblemEngine.h"

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
		PNode head = CreateList(testCase.Data, testCase.Size);
		PNode newHead = ReverseList(head);

		PrintList(newHead);

		FreeList(newHead);
	}

	return 0;
}