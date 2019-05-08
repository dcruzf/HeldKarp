#include "combinations.h"
#include <vector>
#include <unordered_map> 

std::pair < double, std::vector<int> > HeldKarp(const std::vector<std::vector<double>> distance) {
    const int n = distance.size();

    std::unordered_map<std::string, std::pair <double, unsigned int>> umap;
    std::string key;
    std::pair <double, unsigned int> value, best;
    unsigned long bits, prev;

    for (int k = 0; k < n; ++k) {
        key = std::to_string(1 << k) + std::to_string(k); //key as string
        value = std::make_pair(distance[0][k], 0);
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
                best = std::make_pair(n*10, 0); //A matriz de distancia edve estar padronizada entre min 0 e max 1
                for (auto m : subset) {
                    if (m == k) continue;
                    key = std::to_string(prev) + std::to_string(m); // key prev
                    value = std::make_pair(umap[key].first + distance[m][k], m); //new value
                    best = (best.first < value.first)?best:value; // if best < value than best else value
                }
                key = std::to_string(bits) + std::to_string(k);
                umap[key] = best;
            }
        }
    }
    bits = (1 << n) - 2;
    best = std::make_pair(n*10, 0);

    for (int k=1; k < n-1; k++) {
        key = std::to_string(bits) + std::to_string(k); // key prev
        value = std::make_pair(umap[key].first + distance[k][0], k); //new value
        best = (best.first < value.first)?best:value; // if best < value than best else value 
    }

    std::vector <int> path(n+1, 0);
    value = best;
    for (int i=1; i < n; i++) {
        path[i] = value.second;
        key = std::to_string(bits) + std::to_string(path[i]);
        value = umap[key];
        bits = bits & ~(1 << path[i]);
    }
    return std::make_pair(best.first, path);
}