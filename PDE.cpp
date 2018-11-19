#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <fstream>

using namespace std;
int glob;
#define PI 3.14159
#define k 1.62
#define Cp 820
#define densidad 2.71


int main(){
	double v= k/(Cp*densidad);
	int tamanio=40;
	int iteraciones = 100;
	double d[tamanio][tamanio];
	std::ofstream outfile ("datos1.txt");
	
	for(int i=0; i<tamanio; i++)                
    {   
      for (int j=0; j<tamanio; j++) d[i][j] = 0;
    }
    
    
	for(int i=0; i<tamanio; i++) d[i][0] = 100.0;
	
	for (int iteraciones = 0; iteraciones < tamanio; iteraciones++){// iteraciones
		
		for (int i = 1; i < (tamanio - 1); i++){ //direccion-x
			
			for (int j = 1; j < (tamanio - 1); j++){ //direccion-y
			
				d[i][j] = 0.25*(d[i+1][j]+d[i-1][j]+d[i][j+1]+d[i][j-1]);
				
			}
		} 
	}
	return 0;
}

