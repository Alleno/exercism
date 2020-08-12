#include "raindrops.h"
using std::string;
namespace raindrops {
    string convert(const int number)
    {
        string res;
        if (number % 3 == 0)
        {
            res += "Pling";
        }
        if (number % 5 == 0)
        {
            res += "Plang";
        }
        if (number % 7 == 0)
        {
            res += "Plong";
        }
        if (res.empty())
        {
            return std::to_string(number);
        }
        return res;
    }
}  // namespace raindrops
