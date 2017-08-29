#pragma once

#include <memory>

typedef struct node *PNode;

typedef struct node
{
	PNode next;
	int value;
} Node;

PNode CreateList(const std::shared_ptr<int>&  inputArray, int numberOfItems);

PNode ReverseList(PNode head);

void PrintList(PNode head);

void FreeList(PNode head);