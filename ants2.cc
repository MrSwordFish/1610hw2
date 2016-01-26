//ants2.cc
#include <rarray>
#include "init.h"
#include "timestep.h"
#include "antoutput.h"

int main(){
	const int size = 356;
	const int total_ants = 1010;
	const int timesteps = 40;
	const float velscale = 1.9;

	rarray<float,2> velocity_of_ants = initializeVel(size);
	rarray<float,2> number_of_ants = initializeNum(size, total_ants);

	float totants = 0.0;
	for (int t = 0; t < timesteps; t++) {
		printAnts(t, size, totants, number_of_ants);
		rarray<float,2> new_number_of_ants = initializeNewNum(size);
		aSingleStep(new_number_of_ants, velocity_of_ants, number_of_ants, size, totants, velscale);
	}

	return 0;
}