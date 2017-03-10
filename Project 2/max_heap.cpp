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

		text_item returnVal = top();
		data[0] = data[numItems - 1];
		numItems--;
		swap_down(0);
		return returnVal;
	}
}

void max_heap::swap_down(int i) {
	
    int s = i;
    int left = i * 2 + 1;
    int right = left + 1;
    
    if(left < numItems && data[left].freq > data[s].freq)
        s = left;
    
    if(right < numItems && data[right].freq > data[s].freq)
        s = right;
    
    if(s != i){
        text_item tmp = data[i];
        data[i] = data[s];
        data[s] = tmp;
        swap_down(s);
    }
}

void max_heap::insert(const text_item & item) {
	if (full()) {
		throw std::logic_error("Cannot insert, heap array is full!");
	} else {

		data[numItems] = item;
		numItems++;
		swap_up(numItems - 1);
	}
}

void max_heap::swap_up(int i) {
		
	if (i == 0) return;
	int p = (i - 1) / 2;
	if (data[i].freq > data[p].freq) {
		text_item tmp = data[i];
		data[i] = data[p];
		data[p] = tmp;
		swap_up(p);
	}
}

/*
//This is a helper function that will print the heap
void max_heap::printHeap(int node=0, int d=0){
    
    int size = numItems;
    
    if(node >= size)
        return;
    
    //print right child
    printHeap(2 * node + 2, d+1);
    
    //print spacing
    for(int i = 0; i < 10 * d; i++)
        std::cout << " ";
    
    //print value
    std::cout << "(" << data[node].word << ", " << data[node].freq << ")" << "\n" << std::endl;
    
    //print left child
    printHeap(2 * node + 1, d+1);

}
 */
