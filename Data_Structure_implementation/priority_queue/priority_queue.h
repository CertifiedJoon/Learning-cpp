#include <iostream>
#include <memory>
#include <limits>
#include <string>

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

namespace cj{

typedef struct PriorityQueueElement {
	int key_;
	std::string value_;
} PQElement;


class PriorityQueue{
public:
	explicit PriorityQueue(const int size);
	~PriorityQueue();
	PriorityQueue(const PriorityQueue &) = delete;
	PriorityQueue &operator=(const PriorityQueue &) = delete;
	
	// Adds the given key and value to the queue
	void Insert(const int key, const std::string value);
	
	// Outputs all elements of queue
	void PrintDebug() const;
	
	// Returns the prioritized key and value associated with it.
	PQElement *GetMax() const;
	
	// Returns the number of items in PQ
	int GetSize() const;
	
	// Returns true if empty
	bool IsEmpty() const;
	
	// Pops priority
	PQElement *PopMax();
	
	// Remove the node with the given index
	void Remove(int index);
	
	
	
private:
	int size_ = 0;
	int capacity_;
	PQElement* elements_;
	
	// Propagates the element up the tree until the parent node's heap property is satisfied;
	void SiftUp(int index);
	
	// Swaps 2 queue elements with the given indices.
	void Swap(const int index1, const int index2);
	
	// Propagates the given node index down the tree until the subtree's heap property is satisfied.
	void SiftDown(int index);
};

// Turns an array into a heap;
void heapify(int *numbers, int count);

// Sorts the given heapified array
void heap_sort(int *numbers, int count);

// Similar to SiftDown, but works on array of integers
void percolate_down(int *numbers, int count, int index);

}



#endif