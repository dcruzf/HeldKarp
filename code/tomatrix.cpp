#include "tomatrix.h"
#include <vector>

using namespace std;

vector<vector<double>> tomatrix(vector<double> dist, int sinze) {
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