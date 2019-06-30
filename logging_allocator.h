#ifndef __LOG_ALLOC_H
#define __LOG_ALLOC_H

#include <iostream>
#include <string>

template<typename T, typename Allocator, const std::string_view &allocate_tag, const std::string_view &deallocate_tag>
class LoggingAllocator {
public:
	using value_type = T;
	template<class O> struct rebind { typedef LoggingAllocator<O, Allocator, allocate_tag, deallocate_tag> other; };
	T* allocate(std::size_t n) {
		T* ret_ptr = std::allocator_traits<Allocator>::allocate(mAllocator, n);
		std::cerr << allocate_tag 
		          << ": 0x" << std::hex << (void*)ret_ptr 
		          << ", " << std::dec << n << std::endl;
		return ret_ptr;
	}
	void deallocate(T* p, std::size_t n) {
		std::cerr << deallocate_tag 
		          << ": 0x" << std::hex << (void*)p 
		          << ", " << std::dec << n << std::endl;
		return std::allocator_traits<Allocator>::deallocate(mAllocator, p, n);
	}	
private:
	Allocator mAllocator;
};

template<typename T_a, typename Allocator_a,
         const std::string_view &allocate_tag_a, 
         const std::string_view &deallocate_tag_a,
         typename T_b, typename Allocator_b,
         const std::string_view &allocate_tag_b, 
         const std::string_view &deallocate_tag_b>
bool operator==(LoggingAllocator<T_a, Allocator_a, allocate_tag_a, deallocate_tag_a> a, LoggingAllocator<T_b, Allocator_b, allocate_tag_b, deallocate_tag_b>  b) {
	return a.mAllocator==b.mAllocator;
}
template<typename T_a, typename Allocator_a,
         const std::string_view &allocate_tag_a,
         const std::string_view &deallocate_tag_a,
         typename T_b, typename Allocator_b,
         const std::string_view &allocate_tag_b,
         const std::string_view &deallocate_tag_b>
bool operator!=(LoggingAllocator<T_a, Allocator_a, allocate_tag_a, deallocate_tag_a> a, LoggingAllocator<T_b, Allocator_b, allocate_tag_b, deallocate_tag_b>  b) {

	return !(a==b);
}
#endif
