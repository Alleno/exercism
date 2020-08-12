#pragma once
#include <vector>
#include <string>
#include <map>

namespace grade_school {
    class school {
        std::map<int, std::vector<std::string>> _roster;
        // for empty grade lookups, allowed in c++ 17, not sure the difference between this and constexpr
        // from here: https://stackoverflow.com/questions/38043442/how-do-inline-variables-work
        // I suppose i need to get a better understanding of how compilation vs linking works to get this
        static const std::vector<std::string> _empty; 
        public:
        void add(const std::string & name, int grade);
        const std::map<int, std::vector<std::string>> & roster() const{
            return _roster;
        }
        const std::vector<std::string> & grade(int grade) const;
    };

}