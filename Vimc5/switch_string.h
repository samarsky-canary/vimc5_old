#pragma once
#ifndef  SWITCH_STRING_H
#define SWITCH_STRING_H
#include <string>

#define SWITCH(str) switch(swstr::str_hash_for_switch(str))

#define CASE(str)    static_assert(swstr::str_is_correct(str) && (swstr::str_len(str) <= swstr::MAX_LEN),\
"CASE string contains wrong characters, or its length is greater than 9");\
case swstr::str_hash(str, swstr::str_len(str))

#define DEFAULT default
namespace swstr
{
	using uchar = unsigned char;
	using ullong = unsigned long long;

	const uchar MAX_LEN = 9;
	const ullong N_HASH = static_cast<ullong>(-1);


	/* Возведение 128 в степень*/
	constexpr  ullong raise_128_to (const uchar power)
	{
		return 0x1ULL << 7 * power;
	}

	constexpr bool str_is_correct (const char* const str)
	{
		return (static_cast<signed char>(*str) > 0) ? str_is_correct(str + 1) : (*str ? false : true);
	}

	constexpr uchar str_len(const char* const str)
	{
		return *str ? (1 + str_len(str + 1)) : 0;
	}

	constexpr ullong str_hash(const char* const str, const uchar current_len)
	{
		return *str ? (raise_128_to(current_len - 1) 
			* static_cast<uchar>(*str) 
			+ str_hash(str + 1, current_len - 1)) 
		: 0;
	}

	inline ullong str_hash_for_switch(const char* const str)
	{
		return (str_is_correct(str) && (str_len(str) <= MAX_LEN)) ? str_hash(str, str_len(str)) : N_HASH;
	}

	inline ullong str_hash_for_switch(const std::string& str)
	{
		return (str_is_correct(str.c_str()) && (str.length() <= MAX_LEN)) ? str_hash(str.c_str(), str.length()) : N_HASH;
	}
}



#endif
