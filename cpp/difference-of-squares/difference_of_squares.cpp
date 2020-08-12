#include "difference_of_squares.h"

namespace squares {
    unsigned int sum_of_squares(unsigned int upto)
    {
        return upto * (upto + 1) * (2 * upto + 1) / 6;
    }
    unsigned int square_of_sum(unsigned int upto)
    {
        auto s = upto * (upto+1)/2;
        return s*s;
    }
    unsigned int difference(unsigned int upto)
    {
        return square_of_sum(upto) - sum_of_squares(upto);
    }

}