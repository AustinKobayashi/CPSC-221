#include "util.hpp"
#include "tokenizer.hpp"
#include <fstream>
#include <algorithm>
#include <locale>
#include <stdexcept>

static std::string to_lower(std::string str){
	auto loc = std::locale();
	std::transform(str.begin(), str.end(), str.begin(), [&](char ch){
		return std::tolower(ch, loc);
	});
	return str;
}

void load_bst(std::string const& filename, string_bst &tree){
	std::ifstream in(filename);
	if(!in.is_open()){
		throw std::runtime_error("couldn't open file " + filename);
	}
	tokenize(
		" ,.:-!?/%\'\"\r\n",
		std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(),
		[&](std::string token){
			if (token.length() > 0) {
				tree.insert(to_lower(std::move(token)));
			} else {
				std::move(token);
			}
		});
}

max_heap copy_to_heap(string_bst const& t) {
	max_heap h(t.size());
	in_order_copy(t.get_root(), h);
	return h;
}

void in_order_copy(string_bst::node_t const *n, max_heap &h) {
	if (n == NULL) {
		return;
	}
	in_order_copy(n->left, h);
	h.insert(n->data);
	in_order_copy(n->right, h);
}