#include "combinations.h"
#include <vector>
#include <algorithm>

using namespace std;

const vector< vector<int> > combinations(int start, int end, int r) {
    // returns a vector of vectors with indexes of combinations n r by r
    vector< vector<int> > combs;
    vector<bool> v(end - start);
    std::fill(v.end() - r, v.end(), true);
    do {
        int c=0;
        vector <int> line;
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