#pragma once

#include <string>
#include "string_bst.hpp"
#include "max_heap.hpp"

void load_bst(std::string const& filename, string_bst &tree);
max_heap copy_to_heap(string_bst const& t);
void in_order_copy(string_bst::node_t const *n, max_heap &h);