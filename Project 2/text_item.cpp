#include "text_item.hpp"

bool text_item::operator==(text_item const& other) const{
	return freq == other.freq && word == other.word;
}

std::ostream& operator<<(std::ostream& out, text_item const& item){
	out << "text_item{\"" << item.word << "\"," << item.freq << "}";
	return out;
}