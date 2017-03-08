/*-- string_bst.h -------------------------------------------------------------

  This header file defines a Binary Search Tree data type.
  Basic operations:
    constructor:  Constructs an empty tree
    empty:        Checks if a tree is empty
    insert:          Modifies a tree by adding a value at correct location, or updates equivalent value
    root:         Accesses the root of the tree's value; leaves tree unchanged
    remove:       Modifies tree by removing the value with equivalent key
    display:      Displays all the tree's elements
    Note: Execution terminates if memory isn't available for a tree element.
---------------------------------------------------------------------------*/

#pragma once
#include <memory>
#include <stdexcept>
#include <stack>
#include "text_item.hpp"

typedef std::string tree_key;

class string_bst
{
 public:
  struct node_t;
  struct node_t {
	text_item data;
	node_t * left;
	node_t * right;
  };
  /***** Function Members *****/

  /*-----------------------------------------------------------------------
    Construct a Binary Search Tree object.

    Precondition:  None.
    Postcondition: An empty tree object has been constructed.
        (root is initialized to a null pointer).
  -----------------------------------------------------------------------*/
  string_bst();


  /*-----------------------------------------------------------------------
    Class destructor 

    Precondition:  None.
    Postcondition: The nodes in the tree have been deallocated.
  -----------------------------------------------------------------------*/
  ~string_bst(); 

  // implicit copy constructor fix
  string_bst(string_bst&& other){
    root = other.root;
    other.root = nullptr;
    num_nodes = other.num_nodes;
  }

  string_bst& operator=(string_bst&& other){
    std::swap(root, other.root);
    std::swap(num_nodes, other.num_nodes);
    return *this;
  }

  string_bst(string_bst const&) = delete;
  string_bst& operator=(string_bst const&) = delete;
  
  /*-----------------------------------------------------------------------
    Check if tree is empty.

    Precondition:  None.
    Postcondition: Returns true if tree is empty and false otherwise.
  -----------------------------------------------------------------------*/
  bool empty() const;

  /*-----------------------------------------------------------------------
    Add an element to a tree, or update existing TreeElement if an item with
    an equivalent key already exists in the tree.

    Precondition:  key is to be added to this tree
    Postcondition: key is added in the correct location of the tree,
    or item with equivalent key is updated
  -----------------------------------------------------------------------*/
  void insert(tree_key const & key);

  /*-----------------------------------------------------------------------
    Display values stored in the tree

    Precondition:  Tree is nonempty.
    Postcondition: Tree has not been modified, contents have been using
    an inorder traversal.
  -----------------------------------------------------------------------*/  
  void display() const;

  /*-----------------------------------------------------------------------
    Returns the number of elements in the tree. 
    
    Precondition:  Tree is nonempty.
    Postcondition: Tree has not been modified, number of unique elements
    in Tree has been returned.
  -----------------------------------------------------------------------*/    
  int size() const;
  
   /*-----------------------------------------------------------------------
    Returns the freq value of the Tree Node item with equivalent key, or
	zero if no item with an equivalent key is found
    
    Precondition:  Tree is nonempty.
    Postcondition: Tree has not been modified, value of freq for item with
	matching key is returned.
  -----------------------------------------------------------------------*/ 
  int word_frequency(tree_key const& key) const;

  /*-----------------------------------------------------------------------
    Returns a pointer to the root node of the Tree 
    
    Precondition:  Tree is nonempty.
    Postcondition: Tree has not been modified, pointer to root node has
	been returned.
  -----------------------------------------------------------------------*/
  node_t* get_root() const;
  
 private:  
  node_t * root;
  int num_nodes;
  
  void insert_helper(node_t *& n, tree_key const& key);
  void print_in_order(node_t *n) const;
  void remove(node_t *& n);
  
}; // end of class declaration

