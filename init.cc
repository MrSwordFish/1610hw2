#include <rarray>
#include <cmath>
#include "init.h"

rarray<float,2> initializeVel(int size){
	rarray<float,2> velocity_of_ants(size,size);
	for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            velocity_of_ants[i][j] = M_PI*(sin((2*M_PI*(i+j))/(size*10)+1));
        }
    }
	return velocity_of_ants;
}

rarray<float,2> initializeNum(int size, int total_ants){
	rarray<float,2> num(size,size);
	int n = 0;
    float z = 0;
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            num[i][j] = 0.0;
        }
    }
    while (n < total_ants) {
        for (int i=0;i<size;i++) {
            for (int j=0;j<size;j++) {
                z += sin(0.3*(i+j));
                if (z>1 and n!=total_ants) {
                    num[i][j] += 1;
                    n += 1;
                }
            }
        }
    }
    return num;
}

rarray<float,2> initializeNewNum(int size){
	rarray<float,2> new_number_of_ants(size,size);
	for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            new_number_of_ants[i][j] = 0.0;
        }
    }
	return new_number_of_ants;
}