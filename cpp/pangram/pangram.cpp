#include "pangram.h"
#include <bitset>

namespace pangram {
    bool is_pangram(const char* sentence)
    {
        const char* c = sentence;
        std::bitset<26> s;
        while(*c)
        {
            if (isalpha(*c)){
                s[tolower(*c) - 'a']=1;
            }
            c++;
        }
        return s.all();
    }
}  // namespace pangram
