#pragma once

#include <string>
#include <ostream>
#include <iostream>

struct text_item {
	std::string word;  //the word
	int freq;     //the frequency we have seen the word
	bool operator==(text_item const& other) const;
};

std::ostream& operator<<(std::ostream& out, text_item const& item);