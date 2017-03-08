/*--- max_heap.cpp -----------------------------------------------
  This file implements hax_heap.hpp member functions.
-------------------------------------------------------------------------*/

#include "max_heap.hpp"
#include <stdexcept>

max_heap::max_heap(int n){
	data = new text_item[n];
	numItems = 0;
	max_capacity = n;
}

max_heap::~max_heap()
{ 
	delete [] data;
}

bool max_heap::empty() const {
	return (numItems == 0);
}
bool max_heap::full() const {
	return (numItems == max_capacity);
}

int max_heap::size() const {
	return numItems;
}	

text_item& max_heap::top() {
	if (empty()) {
		throw std::logic_error("Heap is empty, can't access top!");
	}
	return data[0];
}


//--- You must comple the following functions: 


text_item max_heap::delete_max() {
	if (empty()) {
		throw std::logic_error("Cannot delete, heap is empty!");
	} else {
		// ADD CODE HERE
		
		// Fix this so it correctly deletes
		// and maintains the heap-order property
		// required for a max-heap
		
		// returning something so it compiles:

		text_item returnVal = top();
		data[0] = data[numItems - 1];
		numItems--;
		swap_down(0);
		return returnVal;
	}
}

void max_heap::swap_down(int i) {
	// ADD CODE HERE
		
	// Fix this so it correctly swaps
}

void max_heap::insert(const text_item & item) {
	if (full()) {
		throw std::logic_error("Cannot insert, heap array is full!");
	} else {
		// ADD CODE HERE
		
		// Fix this so it correctly inserts
		// and maintains the heap-order property
		// required for a max-heap
		data[numItems] = item;
		numItems++;
		swap_up(numItems - 1);
	}
}

void max_heap::swap_up(int i) {
	// ADD CODE HERE
		
	// Fix this so it correctly swaps
	if (i == 0) return;
	int p = (i - 1) / 2;
	if (data[i] >= data[p]) {
		text_item tmp = data[i];
		data[i] = data[p];
		data[p] = tmp;
		swap_up(p);
	}
}
