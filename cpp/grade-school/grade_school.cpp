//
// Created by Allen Wang on 12/8/18.
//

#include "grade_school.h"
#include <vector>
#include <algorithm>

using namespace std;

namespace grade_school{
    void school::add(const string & name, int grade){
        auto& names{_roster[grade]};
        names.insert(std::upper_bound(names.begin(), names.end(), name), name);
    }

    const vector<string> & school::grade(int grade) const{
        if (_roster.find(grade) == _roster.end()){
            return _empty;
        }
        return _roster.at(grade);
    }

    vector<string> _empty{};
}