#pragma once
#include <algorithm>
#include <string>

/**
  Assigns each token in [begin,end) to out.
*/
template<typename InputIterator, typename Fn>
void tokenize(std::string const& token_string, InputIterator begin, InputIterator end, Fn out){
	auto is_separator = [&](char ch){
		return std::any_of(token_string.begin(), token_string.end(), [&](char token_ch){
			return ch == token_ch;
		});
	};
	while(begin != end){
		begin = std::find_if_not(begin, end, is_separator);
		if(begin != end){
			std::string token;
			do{
				token += *begin;
				++begin;
			}while(begin != end && !is_separator(*begin));
			out(std::move(token));
		}
	}
}