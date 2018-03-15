#include "Neuronio.h"
#include <iostream>

Neuronio::Neuronio()
{

}

Neuronio::~Neuronio()
{
    //dtor
}

void Neuronio::Treinar(float LRate) {
    std::cout << "Iniciando Treinamento...\n";
    for(int i = 0 ; i < TARGETS ; i++){
        for (int j = 0 ; j < INPUTS ; j++){
            std::cout << matriz[i][j] << " ";
            x += matriz[i][j] * W[j];
        }
        y = f(x);
        std::cout << "= " << y;
        if (y != target[i]) {
            std::cout << " <- ERRO!\n\n";
            CalibrarPesos(y, i, LRate);
            // reiniciar o treinamento
            i = -1;
        } else {
            std::cout << std::endl;
        }
    }
    std::cout << "Treinamento finalizado. Pesos devidamente ajustados.\n";
}

float Neuronio::f(float x){
    if ( x > 0) {
        return 1;
    } else {
        return 0;
    }
}

void Neuronio::CalibrarPesos(float y, int i, float LRate){
    std::cout << "Recalibrando pesos...\n";
    for(int k = 0 ; k < INPUTS ; k++){
        W[k] = W[k] + ( target[i] - y ) * matriz[i][k] * LRate;
    }
    std::cout << "Pesos Recalibrados!\nW = [ " << W[0] << ", " << W[1] << ", " << W[2] << "]\n\n";
}
