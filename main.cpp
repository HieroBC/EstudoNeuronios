#include <iostream>
#include <cstdio>

#define TARGET_LENGTH 4

using namespace std;

int Fdegrau(int);

int main () {
    bool error = false;
    double target[TARGET_LENGTH] = {0, 0, 0, 1};
    double matrix[4][3] = { 1, 0, 0,
                         1, 0, 1,
                         1, 1, 0,
                         1, 1, 1};
    double neuron[3] = { 0 };
    double degrau = 0;

    while (!error) {
        for (int ax = 0 ; ax < 4 ; ax++){
            for (int i = 0 ; i < 3 ; i++){
                degrau += matrix[ax][i] * neuron[i];
            }
            printf("degrau: %d\n", degrau);
            int y = Fdegrau(degrau);
            if(target[ax] == y){
                printf("ax = %d: OK\n", ax);
                degrau = 0;
            } else {
                printf("ax = %d: erro\n", ax);
                /// ajusta peso
                neuron[0] = neuron[0] + (target[ax] - y) * matrix[ax][0] * 0.5;
                neuron[1] = neuron[1] + (target[ax] - y) * matrix[ax][1] * 0.5;
                neuron[2] = neuron[2] + (target[ax] - y) * matrix[ax][2] * 0.5;
                ax = -1;
                degrau = 0;
                printf("novo peso: [ %d, %d, %d ]\n", neuron[0], neuron[1], neuron[2]);
                continue;

            }
        }

    };

    return 0;
}

int Fdegrau(int degrau){
    if( degrau > 0){
        return 1;
    }else{
        return 0;
    }
}
