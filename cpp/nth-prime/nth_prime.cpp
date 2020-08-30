#include "nth_prime.h"
#include <list>
#include <functional>
#include <algorithm>

namespace nth_prime {

    int nth(int prime)
    {
        if (prime < 1)
            throw std::domain_error("Nth prime must be a counting number");
        std::list<std::function<bool(int)>> list_of_mods;

        int i = 2, nth = 0;
        while (nth != prime)
        {
            if (!any_of(list_of_mods.begin(), list_of_mods.end(), [i](auto fn){return fn(i);}))
            {
                list_of_mods.push_back([i](int x){ return x % i == 0; });
                nth++;
            }
            i++;
        }
        return i-1;
    }
}  // namespace nth_prime
