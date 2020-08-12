#include "grains.h"
#include <cmath>
#include <stdexcept>
#include <limits>

namespace grains {
    unsigned long long square(unsigned int square_number){
        if (square_number > 64) throw std::domain_error("Overflow will be caused by greater than 64 squares");
        // note to self, ULL is a designator for a literal unsigned long long
        if (square_number == 0) return 0;
        return 1ULL << (square_number-1);
    }
    unsigned long long total() {
        return std::numeric_limits<unsigned long long>::max();
    }
}  // namespace grains
