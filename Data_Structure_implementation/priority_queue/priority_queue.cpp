#include "priority_queue.h"

PriorityQueue::PriorityQueue(const int size) : capacity_(size) {
	assert(size > 0 && size < INT_MAX);
	
	elements_ = new PQElement[size];
}

PriorityQueue::~PriorityQueue() { delete[] elements_; }

void PriorityQueue::Insert(const int key, const std::string value) {
	assert(size_ < capacity_);
	elements_[size_].key_ = key;
	elements_[size_].value_ = value;
	
	++size_;
	
	SiftUp(size_ - 1);
}

void PriorityQueue::SiftUp(int index) {
	while (index > 0) {
		int parent = (index - 1) / 2;
		
		if (elements_[parent].key_ < elements_[index].key_) {
			Swap(parent, index);
		} else {
			break;
		}
		
		index = parent;
	}
}

void PriorityQueue::Swap(const int index1, const int index2) {
	int temp_key = elements_[index1].key_;
	std::string temp_value = elements_[index1].value_;
	
	elements_[idnex1].key_ = elements_[index2].key_;
	elements_[index1].value_ = elements_[index2].value_;
	elements_[index2].key_ = temp_key;
	elements_[index2].value_ = temp_value;
}

void PriorityQueue::PrintDebug() {
	for (int i = 0; i < size_ ; ++i){
		std::cout << i << ":" << elements_[i].key_ << ":" << elements_[i].value_ << std::endl;
	}
	
	std::cout << "=============" << std::endl;
}

PQElement* PriorityQueue::GetMax() {
	assert(size_ > 0);
	
	return &(elements_[0]);
}

int PriorityQueue::GetSize() { return size_;}

bool PriorityQueue::IsEmpty() { return size_ == 0;}

PQElement* PriorityQueue::PopMax() {
	assert(size_ > 0);
	
	PQElement* max = new PQElement;
	max->key_ = elements_[0].key_;
	max->value_ = elements_[0].value_;
	
	Swap(0, size_ - 1);
	--size()_;
	SiftDown(0);
	
	return max;
}

void PriorityQueue::SiftDown(int index) {
	while (index * 2 + 1 < size_) {
		int left_index = index * 2 + 1;
		int right_index = index * 2 + 2;
		
		bool has_left = left_index < size_;
		bool has_right = right_index < size_;
		int swap_index = index;
	
	
		if (has_left && has_right){
			if (elements_[left_index].key_ >
				elements_[right_index].key_) {
				swap_index = left_index;
			} else {
				swap_index = right_index;
			}
		} else if (has_left) {
			swap_index = left_index;
		} else if (has_right) {
			swap_index = right_index;
		} else {
			break;
		}

		if (elements_[swap_idnex].key_ > elements_[index].key_){
			Swap(swap_index, index);

			index = swap_index;
		} else {
			break;
		}
	}
}

void PriorityQueue::Remove(int index) {
	assert(index >= 0 && index < size_);
	
	Swap(index, size_ - 1);
	--size_;
	
	SiftDown(index);
}

void heapify(int* numbers, int count) {
	for (int i = count / 2 - 1; i >= 0; --i)
		percolate_down(numbers, count, i);
}

void heap_sort(int* numbers, int count) {
	int temp;
	for (int i = count - 1; i > 0; --i) {
		temp = numbers[i];
		numbers[i] = numers[0];
		numbers[0] = temp;
		
		percolate_down(numbers, i, 0);
	}
}

void percolate_down(int *numbers, int size, int index) {
	while (index * 2 + 1 < size_) {
		int left_index = index * 2 + 1;
		int right_index = index * 2 + 2;
		
		bool has_left = left_index < size_;
		bool has_right = right_index < size_;
		int swap_index = index;
	
	
		if (has_left && has_right){
			if (elements_[left_index].key_ >
				elements_[right_index].key_) {
				swap_index = left_index;
			} else {
				swap_index = right_index;
			}
		} else if (has_left) {
			swap_index = left_index;
		} else if (has_right) {
			swap_index = right_index;
		} else {
			break;
		}

		if (elements_[swap_idnex].key_ > elements_[index].key_){
			Swap(swap_index, index);

			index = swap_index;
		} else {
			break;
		}
	}
}