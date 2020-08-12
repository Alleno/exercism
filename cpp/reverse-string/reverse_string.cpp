#include "reverse_string.h"

namespace reverse_string {
    string reverse_string(const string input)
    {
        string res(input.rbegin(), input.rend());
        return res;
    }
}  // namespace reverse_string
