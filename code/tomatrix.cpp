#include "tomatrix.h"
#include <vector>

std::vector< std::vector< double > > tomatrix( std::vector< double > dist, int sinze) {
    std::vector< std::vector< double > > distance(sinze, std::vector< double >( sinze ));
    int item = 0;
    for (int i=0; i < sinze; i++){
        for (int j=0; j<sinze; j++) {
            distance[i][j] = dist[item];
            item++;
        }
    }
return distance;
}