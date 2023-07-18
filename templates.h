#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <climits>   // CHAR_BIT
#include <cstddef>   // std::size_t
#include <iostream>  // std::cout, std::endl
#include <windows.h>
#include <iomanip>
#include <algorithm>
#include <cctype>

const char* hex_num_cstr = { 0 };
char* hex_num_cstr_m = { 0 };
const char* hex_num_cstr_2 = { 0 };

unsigned long long foo(const char* s) {
    unsigned long long result = 0;
    int c;
    if ('0' == *s && 'x' == *(s + 1)) {
        s += 2;
        while (*s) {
            result = result << 4;
            if (c = (*s - '0'), (c >= 0 && c <= 9)) result |= c;
            else if (c = (*s - 'A'), (c >= 0 && c <= 5)) result |= (c + 10);
            else if (c = (*s - 'a'), (c >= 0 && c <= 5)) result |= (c + 10);
            else break;
            ++s;
        }
    }
    return result;
}

template <class T, class T2 = typename std::enable_if<std::is_integral<T>::value>::type>
static std::string ToHex(const T& data, bool addPrefix = true);



template<class T, class>
inline std::string ToHex(const T& data, bool addPrefix)
{
    std::stringstream sstream;
    sstream << std::hex;
    std::string ret;
    if (typeid(T) == typeid(char) || typeid(T) == typeid(unsigned char) || sizeof(T) == 1)
    {
        sstream << static_cast<int>(data);
        ret = sstream.str();
        if (ret.length() > 2)
        {
            ret = ret.substr(ret.length() - 2, 2);
        }
    }
    else
    {
        sstream << data;
        ret = sstream.str();
    }
    return (addPrefix ? u8"0x0" : u8"") + ret;
}

template <class T>
T reverse_bits(T n) {
    short bits = sizeof(n) * 8;
    T mask = ~T(0); // equivalent to uint32_t mask = 0b11111111111111111111111111111111;

    while (bits >>= 1) {
        mask ^= mask << (bits); // will convert mask to 0b00000000000000001111111111111111;
        n = (n & ~mask) >> bits | (n & mask) << bits; // divide and conquer
    }

    return n;
}
