#pragma once
#include <mutex>

class FineGrainedQueue
{
public:
	struct Node
	{
		int value;
		Node* next;
		std::mutex* node_mutex;
	};

	Node* head;
	std::mutex* queue_mutex;
	FineGrainedQueue();

	void remove(int value);
	void insert(int value);
	void insertIntoMiddle(int value, int pos);
	void print();
};

