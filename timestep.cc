#include <rarray>
#include <cmath>
#include "timestep.h"

void aSingleStep(rarray<float,2> new_number_of_ants,rarray<float,2> velocity_of_ants,rarray<float,2> number_of_ants,int size, float totants, float velscale){
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            int di = velscale*sin(velocity_of_ants[i][j]);
            int dj = velscale*cos(velocity_of_ants[i][j]);
            int i2 = i + di;
            int j2 = j + dj;
            // some ants do not walk
            new_number_of_ants[i][j]+=0.8*number_of_ants[i][j];
            // the rest of the ants walk, but some fall of the table
            if (i2>=0 and i2<size and j2>=0 and j2<size) {
                new_number_of_ants[i2][j2]+=0.2*number_of_ants[i][j];
            }
        }
    }
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            number_of_ants[i][j] = new_number_of_ants[i][j];
            totants += number_of_ants[i][j];
        }
    }
}