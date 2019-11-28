#include <iostream>
#include <cmath>


const float T0 = 0;
const float TL = 0;
const float Tmax = 10;
const float L = 1;
const float rho = 1;
const float T_constant = 0.2;
const float c = sqrt(T_constant/rho);
const float pi = asin(1.0)*2.0;
float dT;
int nT;
int Nx;
float dX;
float c_prime;

void FTCS(float **);
void mostrarMatriz(float **, int, int);

int main(int argc, char **argv){
	
    dT = 0.01;
    dX = 0.01;    
	nT = (int) Tmax/dT;
	Nx = (int) (L/dX + 1);
    c_prime = dX/dT;

	
    float **T = new float*[nT];
    for(int i=0;i<nT;i++){
        T[i] = new float[Nx];
    }
	
	for(int i=0; i<Nx; i++){
		*(*(T+0)+i) = sin(pi*i*dX/L);
	}
    /*
    for(int i = 0; i<Nx; i++){
        if(i == 0 || i == (Nx-1))
            *(*(T+0)+i) = 0;
        else{
            if(i*dX <= 0.8*L)
                *(*(T+0)+i) = 1.25*i*dX/L;
            else
                *(*(T+0)+i) = 5 - 5*i*dX/L;
        }
    }*/
	
    FTCS(T);
    mostrarMatriz(T, nT, Nx);
	
    for(int i=0;i<nT;i++){
        delete[] T[i];
    }
    return 0;
}

void FTCS(float **T){
    /*Se empieza en el caso de j=1. Es decir la segunda iteración temporal.*/
    for(int i=0; i<Nx; i++){
        if(i == 0) 
            *(*(T+1)+i) = T0;
        else if(i == (Nx - 1))
            *(*(T+1)+i) = TL;
        else
            *(*(T+1)+i) = *(*(T+0)+i) + pow(c,2)/(2*pow(c_prime,2))*( *(*(T+0)+i+1) + *(*(T+0)+i-1) - *(*(T+0)+i)*2 );
    }// Se completan los demás casos.
    
    for(int j=2; j<nT; j++){
        for(int i=0; i<Nx; i++){
            if(i == 0)
                *(*(T+j)+i) = T0;
            else if(i == (Nx - 1))
                *(*(T+j)+i) = TL;
            else
                *(*(T+j)+i) = *(*(T+j-1)+i)*2 - *(*(T+j-2)+i) + pow(c,2)/pow(c_prime,2)*( *(*(T+j-1)+i+1) + *(*(T+j-1)+i-1) - *(*(T+j-1)+i)*2 );
        }
    }
}

void mostrarMatriz(float **Matriz, int filas, int col){
    for(int i=0;i<filas;i++){
        for(int j=0;j<col;j++){
            std::cout<<*(*(Matriz+i)+j)<<"\t";
            
        }
        std::cout<<std::endl;
    }
}