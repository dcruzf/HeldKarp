#include "tomatrix.h"
#include "heldkarptsp.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<double> dist = {0.    , 0.2666, 0.2517, 0.3179, 0.2908, 0.2666, 0.    , 0.4678,
                           0.5527, 0.2966, 0.2517, 0.4678, 0.    , 0.0923, 0.539 , 0.3179,
                           0.5527, 0.0923, 0.    , 0.593 , 0.2908, 0.2966, 0.539 , 0.593 ,
                           0.    };
    int sinze = 5;
    auto distance = tomatrix(dist, sinze);
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