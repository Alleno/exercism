#include "sieve.h"
#include <numeric>

namespace sieve {
    std::vector<int> primes(int upto)
    {
        std::vector<int> all_values(upto-1); // or should we just default init and then call .reserve?
        std::iota(all_values.begin(), all_values.end(), 2);

        for (auto val : all_values)
        {
            if (val == 0) continue;
            int index = val - 2;
            for (std::vector<int>::size_type i = index+val; i < all_values.size(); i += val)
            {
                all_values[i] = 0;
            }
        }
        auto new_end = remove_if(all_values.begin(), all_values.end(), [](int x) { return  x == 0; });
        all_values.erase(new_end, all_values.end());
        return all_values; //https://stackoverflow.com/questions/15704565/efficient-way-to-return-a-stdvector-in-c
    }
}  // namespace sieve
