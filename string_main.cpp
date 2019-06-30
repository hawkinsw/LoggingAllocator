#include <string>
#include <iostream>
#include <vector>

#include "logging_allocator.h"
constexpr std::string_view allocate_tag = "allocate";
constexpr std::string_view deallocate_tag = "deallocate";

using allocd_str = std::basic_string<char, std::char_traits<char>, LoggingAllocator<char, std::allocator<char>, allocate_tag, deallocate_tag> >;

void make_very(allocd_str &str) {
	std::cerr << "(start) make_very" << std::endl;
	str = "This is a very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very, very long word long sentence.";
	std::cerr << "(stop) make_very" << std::endl;
}

void make_really(allocd_str &str) {
	std::cerr << "(start) make_really" << std::endl;
	str = "This is a really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really, really long sentence.";
	make_very(str);
	std::cerr << "(stop) make_really" << std::endl;
}

int main(void) {
	allocd_str str = "testing";
	make_really(str);
	return 0;
}
