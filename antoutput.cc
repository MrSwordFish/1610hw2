#include <rarray>
#include <iostream>
#include "antoutput.h"

void printAnts(int time, int size,float totants,rarray<float,2> number_of_ants){
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            totants += number_of_ants[i][j];
        }
    }
    std::cout << time << " " << totants << std::endl;
}
