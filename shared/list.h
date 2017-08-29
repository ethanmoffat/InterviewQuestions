#pragma once

#include <memory>

typedef struct node *PNode;

typedef struct node
{
	PNode next;
	int value;
} Node;

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