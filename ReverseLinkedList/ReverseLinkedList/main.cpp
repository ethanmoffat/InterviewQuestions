#include <iostream>
#include <fstream>
#include <memory>

typedef struct node
{
	node * next;
	int value;
} Node, *PNode;

PNode CreateList(const std::shared_ptr<int>&  inputArray, int numberOfItems);
PNode ReverseList(PNode head);
void PrintList(PNode head);
void FreeList(PNode head);

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

		PrintList(head);
		PrintList(newHead);
		FreeList(head);
		FreeList(newHead);

		std::cout << std::endl;
	}

	inputFile.close();

	return 0;
}

PNode CreateList(const std::shared_ptr<int>&  inputArray, int numberOfItems)
{
	if (numberOfItems < 1)
		return nullptr;

	PNode head = new Node;
	PNode current = head;
	for (int i = 0; i < numberOfItems; ++i)
	{
		current->next = i + 1 == numberOfItems ? nullptr : new Node;
		current->value = inputArray.get()[i];
		current = current->next;
	}

	return head;
}

PNode ReverseList(PNode head)
{
	return nullptr;
}

void PrintList(PNode head)
{
	PNode current = head;
	while (current != nullptr)
	{
		std::cout << current->value << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

void FreeList(PNode head)
{
	PNode current = head;
	while (current != nullptr)
	{
		PNode tmp = current;
		current = current->next;
		delete tmp;
	}
}