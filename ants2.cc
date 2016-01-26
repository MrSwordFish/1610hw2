//ants2.cc
#include <rarray>
#include "init.h"
#include "timestep.h"
#include "antoutput.h"

int main(){
	const int size = 356;
	const int total_ants = 1010;
	const int timesteps = 60;

	rarray<float,2> velocity_of_ants = initializeVel(size);
	rarray<float,2> number_of_ants = initializeNum(size, total_ants);

	printAnts(0, size, number_of_ants);

	return 0;
}