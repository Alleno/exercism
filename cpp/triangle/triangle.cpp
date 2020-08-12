#include "triangle.h"
#include <algorithm>
#include <stdexcept>
#include <cmath>

namespace{
    void sort_triple(double& smallest, double& middle, double& largest){
        // sorts the inputs into the smallest, middle, and the largest by reference
        if (middle < smallest) std::swap(smallest, middle);
        if (largest < middle) std::swap(middle, largest);
        if (middle < smallest) std::swap(smallest, middle);
    }

    bool almost_equal(double val1, double val2){
        if (val2 > val1){
            return val2 <= std::nexttoward(val1, val2);
        }
        else if (val1 > val2) {
            return val2 >= std::nexttoward(val1, val2);
        }
        else return true;
    }
}

namespace triangle {
    flavor kind(double side_length1, double side_length2, double side_length3){
        sort_triple(side_length1, side_length2, side_length3);
    
        if (side_length1 <= std::nexttoward(0.0, side_length1)) { 
            throw std::domain_error("negative or zero side length");
        }
        if (side_length1 + side_length2 < std::nexttoward(side_length3, side_length1)){
            throw std::domain_error("one side longer than the sum of the other two");
        }
        if (almost_equal(side_length1, side_length3)) {
            return flavor::equilateral;
        }
        else if (almost_equal(side_length1, side_length2) || almost_equal(side_length2, side_length3)) {
            return flavor::isosceles;
        }
        else return flavor::scalene;
    }
}  // namespace triangle
