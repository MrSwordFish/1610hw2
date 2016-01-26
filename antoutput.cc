#include <rarray>
#include <rarrayio>
#include <iostream>
#include "antoutput.h"

void printTest(rarray<float,2> number_of_ants){
	std::cout << number_of_ants << std::endl;
}

void printAnts(int time, int size, rarray<float,2> number_of_ants){
	float totants = 0.0;
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            totants += number_of_ants[i][j];
        }
    }
    std::cout << time << " " << totants << std::endl;
}
