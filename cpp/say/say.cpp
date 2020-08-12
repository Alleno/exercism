#include "say.h"
#include <map>
#include <list>

using std::string;
using std::map;
using std::list;

namespace {
    static const map<int, string> lookup = {
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
        {10, "ten"},
        {11, "eleven"},
        {12, "twelve"},
        {13, "thirteen"},
        {14, "fourteen"},
        {15, "fifteen"},
        {16, "sixteen"},
        {17, "seventeen"},
        {18, "eighteen"},
        {19, "nineteen"},
        {20, "twenty"},
        {30, "thirty"},
        {40, "forty"},
        {50, "fifty"},
        {60, "sixty"},
        {70, "seventy"},
        {80, "eighty"},
        {90, "ninety"}
    };
    static auto const l_end = lookup.end();

    static const list<string> digits = {"thousand", "million", "billion"};


    // get string representation up to 99
    string get_string_lt_100(int number)
    {
        auto it = lookup.find(number);
        if (it != l_end){
            return it->second;
        }
        else {
            int tens = number / 10 * 10;
            int remainder = number % 10;
            return lookup.at(tens) + "-" + lookup.at(remainder);
        }

    }

    string get_string_lt_1000(int number)
    {
        int hundreds_digit = number/100;
        int tens_digits = number%100;
        string ret_value;
        if (hundreds_digit != 0){
            ret_value = lookup.at(hundreds_digit) + " hundred";
        }
        if (tens_digits != 0) {
            if (ret_value != "") ret_value += " ";
            ret_value += get_string_lt_100(tens_digits);
        }
        return ret_value;
    }

}

namespace say {
    string in_english(unsigned long long number)
    {
        if (number < 0 | number >= 1'000'000'000'000ULL)
        {
            throw std::domain_error("Number must be between 0 and 1 less than a trillion");
        }
        else if (number == 0)
        {
            return "zero";
        }

        list<string> output;
        int hundreds = number % 1000;
        if (hundreds != 0)
        {
            output.push_back(get_string_lt_1000(hundreds));
        }
        number /= 1000;
        auto place_it = digits.begin();
        while (number != 0){
            int hundreds = number % 1000;
            if (hundreds != 0){
                string digit_string = *place_it;
                string value = get_string_lt_1000(hundreds);
                output.push_back(value + " " + digit_string);
            }
            number = number / 1000;
            place_it ++;
        }

        auto it = output.rbegin();
        string output_string = *it;
        it++;
        while (it != output.rend())
        {
            output_string += (" " + *it);
            it++;
        }
        return output_string;
    }
}  // namespace say