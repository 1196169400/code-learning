#ifndef MYTINYSTL_BASIC_STRING_H_
#define MYTINYSTL_BASIC_STRING_H_

#include <iostream>

#include "iterator.h"
#include "memory.h"
#include "functional.h"
#include "exceptdef.h"

namespace mystl
{

template<typename CharType>
struct char_traits
{
	typedef CharType char_type; //结构体内外的命名风格
	
	static size_t length(const char_type* str) {}
	
	static int compare(const char_type* s1, const char_type* s2, size_t n) {}
	
	static char_type* copy(char_type* dst, const char_type* src, size_t n) {}
	
	static char_type* move(char_type* dst, const char_type* src, size_t n) {}
	
	static char_type* fill(char_type* dst, char_type ch, size_t count) {}
	
}

template <typename CharType, typename CharTraits = mystl::char_traits<CharType>>
class basic_string
{
public:
	typedef CharTraits						traits_type;
	typedef CharTraits						char_traits;
	
	typedef std::allocator<CharType>		allocator_type;
	typedef std::allocator<CharType>		data_allocator;
	
	typedef typename allocator_type::value_type				value_type;      //typename表示后面是类型，而不是成员
	typedef typename allocator_type::pointer				pointer;
	typedef typename allocator_type::const_pointer   		const_pointer;
	typedef typename allocator_type::reference       		reference;
	typedef typename allocator_type::const_reference 		const_reference;
	typedef typename allocator_type::size_type       		size_type;
	typedef typename allocator_type::difference_type 		difference_type;
	
	typedef value_type*                              		iterator;
	typedef const value_type*                        		const_iterator;
	typedef mystl::reverse_iterator<iterator>        		reverse_iterator;
	typedef mystl::reverse_iterator<const_iterator>  		const_reverse_iterator;
	
	static constexpr size_type npos = static_cast<size_type>(-1);
	
private:
	iterator buffer_;
	size_type size_;
	size_type cap_;
	
public:
	/**
	共九个构造函数
	*/
	basic_string() noexcept {}   //默认构造
	
	basic_string(size_type n, value_type ch) {}
	
	basic_string(const basic_string& other, size_type pos) {}
	
	basic_string(const basic_string& other, size_type pos, size_type count) {}
	
	basic_string(const_pointer str) {}
	
	basic_string(const_pointer str, size_type count) {}
	
	template<typename Iter, typename std::enable_if<std::is_input_iterator<Iter>::value, int>::type = 0>
	basic_string(Iter first, Iter last) {}
	
	basic_string(const basic_string& rhs) {}    //拷贝构造
	
	basic_string(basic_string&& rhs) noexpect {}  //移动构造

}
	
}

#endif // ! MYTINYSTL_BASIC_STRING_H_