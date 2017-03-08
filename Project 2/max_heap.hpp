/*-- max_heap.h -------------------------------------------------------------

  This header file defines a Max Heap data type.
  Basic operations:
    empty:        Checks if a heap is empty
    insert:       Modifies a heap by adding a value at valid location
    deleteMax:    Modifies tree by removing the value with maximum priority
	size:         Produces the number of items currently in a heap
---------------------------------------------------------------------------*/
#pragma once
#include <vector>
#include "text_item.hpp"

class max_heap
{
 private:
  /***** Data Members *****/
  text_item *data;
  int numItems;
  int max_capacity;
  
  void swap_down(int i);
  void swap_up(int i);
	
 public:
  /***** Function Members *****/

  /***** Constructors *****/
  /*-----------------------------------------------------------------------
    Construct a heap object, with an underlying array of size n

    Precondition:  None.
    Postcondition: An empty heap object has been constructed.
  -----------------------------------------------------------------------*/	
  max_heap(int n);

  /***** Destructor *****/
  /*-----------------------------------------------------------------------
    Class destructor 

    Precondition:  None.
    Postcondition: The items in the data array have been deallocated
  -----------------------------------------------------------------------*/
  ~max_heap(); 

  // implicit copy constructor fix
  max_heap(max_heap&& other){
    data = other.data;
    other.data = nullptr;
    numItems = other.numItems;
    max_capacity = other.max_capacity;
  }
  max_heap& operator=(max_heap&& other){
    std::swap(data, other.data);
    numItems = other.numItems;
    max_capacity = other.max_capacity;
    return *this;
  }

  max_heap(max_heap const&) = delete;
  max_heap& operator=(max_heap const&) = delete;
  
  /*-----------------------------------------------------------------------
    Check if heap is empty.

    Precondition:  None.
    Postcondition: Returns true if heap is empty and false otherwise.
  -----------------------------------------------------------------------*/
  bool empty() const;

  /*-----------------------------------------------------------------------
    Check if heap is full.

    Precondition:  None.
    Postcondition: Returns true if heap is full and false otherwise.
  -----------------------------------------------------------------------*/
  bool full() const;

  /*-----------------------------------------------------------------------
    Returns the number of elements currently in a heap. 
    
    Precondition:  Heap is nonempty.
    Postcondition: Heap has not been modified, number of unique elements
    in Heap has been returned.
  -----------------------------------------------------------------------*/	
  int size() const;

  /*-----------------------------------------------------------------------
    Returns a reference to the top of the heap.
    
    Precondition:  Heap is nonempty.
    Postcondition: Heap has not been modified, a reference to the 
	top of the Heap is returned.
  -----------------------------------------------------------------------*/	
  text_item& top();
  
  /*-----------------------------------------------------------------------
    Removes the item with the highest key from the heap.

    Precondition:  None.
    Postcondition: The item with the maximum key value has been removed.
	From the remaining items, the item with the maximum key is now at 
	the top of the heap.
  -----------------------------------------------------------------------*/
  text_item delete_max();
  
  /*-----------------------------------------------------------------------
    Add an item to the heap, and makes sure the order invariant is
	not violated for any parent-child pair.

    Precondition:  w is to be added to the heap
    Postcondition: w is added and heap invariant holds
  -----------------------------------------------------------------------*/
  void insert(text_item const& item);
  
}; // end of class declaration
