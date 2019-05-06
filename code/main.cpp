#include "tomatrix.h"
#include "heldkarptsp.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    vector<double> 
    dist = {0.    , 0.311 , 0.2301, 0.1339, 0.7314, 0.7114, 0.7793, 0.3455,
            0.415 , 0.183 , 0.311 , 0.    , 0.119 , 0.4316, 0.543 , 0.4473,
            0.5796, 0.3513, 0.352 , 0.4758, 0.2301, 0.119 , 0.    , 0.3623,
            0.5283, 0.483 , 0.5723, 0.3918, 0.4177, 0.3733, 0.1339, 0.4316,
            0.3623, 0.    , 0.8633, 0.8447, 0.9116, 0.3591, 0.444 , 0.1708,
            0.7314, 0.543 , 0.5283, 0.8633, 0.    , 0.2228, 0.0527, 0.894 ,
            0.8896, 0.8   , 0.7114, 0.4473, 0.483 , 0.8447, 0.2228, 0.    ,
            0.2188, 0.785 , 0.7607, 0.8257, 0.7793, 0.5796, 0.5723, 0.9116,
            0.0527, 0.2188, 0.    , 0.9307, 0.923 , 0.8516, 0.3455, 0.3513,
            0.3918, 0.3591, 0.894 , 0.785 , 0.9307, 0.    , 0.0902, 0.51  ,
            0.415 , 0.352 , 0.4177, 0.444 , 0.8896, 0.7607, 0.923 , 0.0902,
            0.    , 0.5874, 0.183 , 0.4758, 0.3733, 0.1708, 0.8   , 0.8257,
            0.8516, 0.51  , 0.5874, 0.};
    int size = sqrt(dist.size());
    auto distance = tomatrix(dist, size);
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