/*--- string_bst.C -----------------------------------------------
  This file implements string_bst.hpp member functions.
-------------------------------------------------------------------------*/

#include "string_bst.hpp"

string_bst::string_bst(){
	root = NULL;
	num_nodes = 0;
}

string_bst::~string_bst()
{ 
	remove(root);
}

void string_bst::remove(node_t *& n) {
	if (n != NULL) {
		remove(n->left);
		remove(n->right);
		delete n;
		n = NULL;
	}
}

bool string_bst::empty() const
{ 
   	return (root == 0); 
}

void string_bst::insert(const tree_key & key)
{
   	insert_helper(root, key);
}

void string_bst::insert_helper(node_t *& n, tree_key const & key) {
	if( n == NULL ) {
	  	n = new node_t{text_item{key, 1}, NULL, NULL};
	  	num_nodes++;
  	} else if (n->data.word == key) {
	  	n->data.freq++;
  	} else if (key < n->data.word) {
		insert_helper(n->left, key);
  	} else {
	  	insert_helper(n->right, key);
  	}
}

void string_bst::display() const {
   print_in_order(root);
   std::cout << std::endl;
}

void string_bst::print_in_order(node_t *n) const {
	if (n == NULL) {
		return;
	}
	print_in_order( n->left );
	std::cout << n->data.word << ":" << n->data.freq << ", ";
	print_in_order( n->right );
}

int string_bst::size() const {
	return num_nodes;	
}

string_bst::node_t* string_bst::get_root() const {
	return root;
}

int string_bst::word_frequency(const tree_key &key) const {
	
	// ADD CODE HERE
		
	return 0;
}

