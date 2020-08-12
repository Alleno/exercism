//
// Created by Allen Wang on 12/30/18.
//

#include "rna_transcription.h"
#include <map>
#include <algorithm>

using std::transform; using std::map; using std::string;

namespace {
    const map<char, char> rna_map = {{'A', 'U'}, {'T', 'A'}, {'G', 'C'}, {'C', 'G'}};
}

char transcription::to_rna(const char chr){
    return rna_map.at(chr);
};

string transcription::to_rna(const string& str){
    string res;
    res.reserve(str.size());
    transform(str.begin(), str.end(), std::back_inserter(res), [](const char c){return transcription::to_rna(c);});
    return res;
};







