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
	
	std::ofstream outfile ("datos1.txt");
	
	return 0;
}

