#include <string>
#include <iostream>
#include <vector>

#include "logging_allocator.h"
constexpr std::string_view allocate_tag = "allocate";
constexpr std::string_view deallocate_tag = "deallocate";

using allocd_vector = std::vector<int, LoggingAllocator<int, std::allocator<int>, allocate_tag, deallocate_tag> >;

void make_very(allocd_vector &vec) {
	std::cerr << "(start) make_very" << std::endl;
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	std::cerr << "(stop) make_very" << std::endl;
}

void make_really(allocd_vector &vec) {
	std::cerr << "(start) make_really" << std::endl;
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	vec.push_back(5);
	make_very(vec);
	std::cerr << "(stop) make_really" << std::endl;
}

int main(void) {
	allocd_vector vec = {0};
	make_really(vec);
	return 0;
}
