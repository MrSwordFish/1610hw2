#include <cmath>
#include <iostream>
int main()
{
    int size = 356;
    // ants walk on a table
    float number_of_ants[size][size];
    float new_number_of_ants[size][size];
    float velocity_of_ants[size][size];
    const int total_ants = 1010; // initial number of ants
    // initialize
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            velocity_of_ants[i][j] = M_PI*(sin((2*M_PI*(i+j))/(size*10)+1));
        }
    }
    int n = 0;
    float z = 0;
    for (int i=0;i<size;i++) {
        for (int j=0;j<size;j++) {
            number_of_ants[i][j] = 0.0;
        }
    }
    while (n < total_ants) {
        for (int i=0;i<size;i++) {
            for (int j=0;j<size;j++) {
                z += sin(0.3*(i+j));
                if (z>1 and n!=total_ants) {
                    number_of_ants[i][j] += 1;
                    n += 1;
                }
            }
        }
    }
    // run simulation
    for (int t = 0; t < 40; t++) {
        float totants = 0.0;
        for (int i=0;i<size;i++) {
            for (int j=0;j<size;j++) {
                totants += number_of_ants[i][j];
            }
        }
        std::cout << t<< " " << totants << std::endl;
        for (int i=0;i<size;i++) {
            for (int j=0;j<size;j++) {
                new_number_of_ants[i][j] = 0.0;
            }
        }
        for (int i=0;i<size;i++) {
            for (int j=0;j<size;j++) {
                int di = 1.9*sin(velocity_of_ants[i][j]);
                int dj = 1.9*cos(velocity_of_ants[i][j]);
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
    return 0;
}             
 