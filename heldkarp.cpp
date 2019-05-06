#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map> 

using namespace std;

// Matrix of distances
vector<vector<double>> get_dist(vector<double> dist, int sinze) {
    vector<vector<double>> distance(sinze, vector<double>(sinze));
    int item = 0;
    for (int i=0; i < sinze; i++){
        for (int j=0; j<sinze; j++) {
            distance[i][j] = dist[item];
            item++;
        }
    }
return distance;
}


//Cobinations
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

// HeldKarp
pair < double, vector<int> > HeldKarp(const vector<vector<double>> distance) {
    const int n = distance.size();

    unordered_map<string, pair <double, unsigned int>> umap;
    string key;
    pair <double, unsigned int> value, best;
    unsigned long bits, prev;

    for (int k = 0; k < n; ++k) {
        key = to_string(1 << k) + to_string(k); //key as string
        value = make_pair(distance[0][k], 0);
        umap[key] = value;
    }

    for (int subsize = 2; subsize < n; subsize++) {
        for (auto subset : combinations(1, n, subsize)) {
            // A subset of nodes {0,2,3,5} can be represented by the 2^0+2^3+2^5=10101 in base 2
            bits = 0;
            for (auto bit : subset) {
                bits |= 1 << bit;
            }

            for (auto k : subset) {
                prev = bits & ~(1 << k);
                best = make_pair(n*10, 0); //A matriz de distancia edve estar padronizada entre min 0 e max 1
                for (auto m : subset) {
                    if (m == k) continue;
                    key = to_string(prev) + to_string(m); // key prev
                    value = make_pair(umap[key].first + distance[m][k], m); //new value
                    best = (best.first < value.first)?best:value; // if best < value than best else value
                }
                key = to_string(bits) + to_string(k);
                umap[key] = best;
            }
        }
    }
    bits = (1 << n) - 2;
    best = make_pair(n*10, 0);

    for (int k=1; k < n-1; k++) {
        key = to_string(bits) + to_string(k); // key prev
        value = make_pair(umap[key].first + distance[k][0], k); //new value
        best = (best.first < value.first)?best:value; // if best < value than best else value 
    }

    vector <int> path(n+1, 0);
    value = best;
    for (int i=n-1; i > 0; i--) {
        path[i] = value.second;
        cout << value.second << " ";
        key = to_string(bits) + to_string(path[i]);
        value = umap[key];
        bits = bits & ~(1 << path[i]);
    }
    return make_pair(best.first, path);
}




int main() {
    vector<double> dist = {0.    , 0.2666, 0.2517, 0.3179, 0.2908, 0.2666, 0.    , 0.4678,
                           0.5527, 0.2966, 0.2517, 0.4678, 0.    , 0.0923, 0.539 , 0.3179,
                           0.5527, 0.0923, 0.    , 0.593 , 0.2908, 0.2966, 0.539 , 0.593 ,
                           0.    };
    int sinze = 5;
    auto distance = get_dist(dist, sinze);
    cout << "Distance matrix:" << endl << endl;
    for (auto v  : distance) {
        for (auto u : v) {
            cout << u << "  ";
        }
        cout << endl;
    }

    auto result = HeldKarp(distance);

    cout << endl << endl << "REULTADO" << endl;
    cout << "Distance: " << result.first << endl;
    cout << "Path: "; 
        for (auto node : result.second) {
        cout << node << " ";
    }
    return 0;
}