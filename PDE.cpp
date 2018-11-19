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
#define densidad 2710
#define diametro 10

int main(){
	double v= k/(Cp*densidad);
	int tamanio=100;
	double dx = 50.0/10000.0;
	double dy = 50.0/10000.0;
	double dt = dx/v*0.001;
	cout << dt << endl;
	double presente[tamanio][tamanio];
	double futuro[tamanio][tamanio];
	
	for(int i=0; i<tamanio;i++){
	    for(int j=0; j<tamanio; j++){
		if(((i-50.0)*(i-50.0)+(j-50.0)*(j-50.0))<(5.0*5.0)){
			presente[i][j]=100;
			}
		else {
		    presente[i][j]=10;
		    }	
	cout << presente[i][j] <<" ";
		}  
	cout << endl;
        }

	for(int i=0; i<tamanio;i++){
		    for(int j=0; j<tamanio; j++){
			if(((i-50.0)*(i-50.0)+(j-50.0)*(j-50.0))<(5.0*5.0)){
				futuro[i][j]=100;
				}
			else {
			    futuro[i][j]=presente[i][j]+ (((v*dt)/(dx*dx))*(presente[i+1][j]-2*presente[i][j]+presente[i-1][j])+ ((v*dt)/(dy*dy)*(presente[i][j+1]-2*presente[i][j]+presente[i][j-1])));
			    }	
		cout << futuro[i][j] <<" ";
			}  
		cout << endl;
		}
	
	
	
	return 0;
}

