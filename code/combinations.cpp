#include "combinations.h"
#include <vector>
#include <algorithm>

const std::vector< std::vector<int> > combinations(int start, int end, int r) {
    // returns a std::vector of std::vectors with indexes of combinations n r by r
    std::vector< std::vector<int> > combs;
    std::vector<bool> v(end - start);
    std::fill(v.end() - r, v.end(), true);
    do {
        int c=0;
        std::vector <int> line;
        for (int i=0; i < end-start; ++i) {
            if (v[i]) {
                line.push_back(i+start);
                ++c;
            }
        }
        combs.push_back(line);
    } while (next_permutation(v.begin(), v.end()));
    return combs;
}