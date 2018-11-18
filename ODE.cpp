#include <iostream>
#include <cmath>
#include <math.h>
#include <cstdlib>
#include <fstream>

using namespace std;
int glob;
#define PI 3.14159
#define c 0.2
#define g 10
#define m 0.2

double dxdt(double t, double x, double x_dev);
double dydt(double t, double y, double y_dev);
double dxdt2(double t, double x, double angulo,double x_dev);
double dydt2(double t, double y, double angulo, double y_dev);
void rungeKutta_4(double *x, double *y, double *x_dev,double *y_dev, double h);


double dxdt(double t, double x, double x_dev){
	return x_dev;
}

double dydt(double t, double y, double y_dev){
	return y_dev;
}

//Componente en x
double dxdt2(double t, double x, double angulo,double x_dev, double y_dev){
	return 0-(c/m)*(x_dev)*(sqrt(x_dev*x_dev+y_dev*y_dev));
}
//componente en y
double dydt2(double t, double y, double angulo, double y_dev, double x_dev){
	return -1.0/1.2*g-(c/m)*(y_dev)*(sqrt(x_dev*x_dev+y_dev*y_dev));
}	

void rungeKutta_4(double *x, double *y, double *x_dev,double *y_dev, double h){
  double x_inicial, y_inicial, ydev_inicial;
  double xdev_inicial;
  
  double kx_1, kx_2, kx_3, kx_4;
  double ky_1, ky_2, ky_3, ky_4;
  double kdx_1, kdx_2,kdx_3, kdx_4;
  double kdy_1, kdy_2,kdy_3, kdy_4;
  
	
  x_inicial = *x;
  y_inicial = *y;
  xdev_inicial = *x_dev;
  ydev_inicial = *y_dev;
  double t=0;
  double angulo= 45;
  kx_1  = dxdt(t,x_inicial,xdev_inicial);
  ky_1  = dydt(t,y_inicial,ydev_inicial);
  kdx_1 = dxdt2(t,x_inicial,angulo,xdev_inicial,ydev_inicial);
  kdy_1 = dydt2(t,y_inicial,angulo,ydev_inicial,xdev_inicial);
  
  kx_2  = dxdt(t+h*0.5, x_inicial+kx_1*0.5*h, xdev_inicial+kdx_1*0.5*h);
  ky_2  = dydt(t+h*0.5, y_inicial+ky_1*0.5*h, ydev_inicial+kdy_1*0.5*h);
  kdx_2 = dxdt2(t+h*0.5, x_inicial+kx_1*0.5*h,angulo,xdev_inicial+kdx_1*0.5*h,ydev_inicial+kdy_1*0.5*h);
  kdy_2 = dydt2(t+h*0.5, y_inicial+ky_1*0.5*h,angulo,ydev_inicial+kdy_1*0.5*h,xdev_inicial+kdx_1*0.5*h);
		
  kx_3  = dxdt(t+h*0.5, x_inicial+kx_2*0.5*h, xdev_inicial+kdx_2*0.5*h);
  ky_3  = dydt(t+h*0.5, y_inicial+ky_2*0.5*h, ydev_inicial+kdy_2*0.5*h);
  kdx_3 = dxdt2(t+h*0.5, x_inicial+kx_2*0.5*h,angulo,xdev_inicial+kdx_2*0.5*h,ydev_inicial+kdy_2*0.5*h);
  kdy_3 = dydt2(t+h*0.5, y_inicial+ky_2*0.5*h,angulo,ydev_inicial+kdy_2*0.5*h,xdev_inicial+kdx_2*0.5*h);

  kx_4  = dxdt(t+h, x_inicial+kx_3*h,xdev_inicial+kdx_3*h);
  ky_4  = dydt(t+h, y_inicial+ky_3*h,ydev_inicial+kdy_3*h);
  kdx_4 = dxdt2(t+h, x_inicial+kx_3*h, angulo,xdev_inicial+kdy_3*h,ydev_inicial+kdy_3*0.5*h);
  kdy_4 = dydt2(t+h, y_inicial+ky_3*h,angulo, ydev_inicial+kdy_3*h,xdev_inicial+kdx_3*0.5*h);

  x_inicial = x_inicial + h * (kx_1 + 2*kx_2 + 2*kx_3 + kx_4)/6.0;
  y_inicial = y_inicial + h * (ky_1 + 2*ky_2 + 2*ky_3 + ky_4)/6.0;
  xdev_inicial = xdev_inicial + h * (kdx_1+2*kdx_2+2*kdx_3+kdx_4)/6.0;
  ydev_inicial = ydev_inicial + h * (kdy_1+2*kdy_2+2*kdy_3+kdy_4)/6.0;

   t =  t + h ;
  *x = x_inicial;
  *y = y_inicial;
  *x_dev = xdev_inicial;
  *y_dev= ydev_inicial;
  
}


int main(){
  double x=0;
  double y=0;
  double t=0;
  double h=0.001;
  double angulo=45;
  double x_dev= 300*cos(angulo*PI/180);
  double y_dev= 300*sin(angulo*PI/180);
  
  ofstream outfile("datos45.txt");
  while(y>=0){
    outfile << t <<" " << x << " " << y << " " << x_dev << " " << y_dev <<endl;		
	cout << t <<" " << x << " " << y << " " << x_dev << " " << y_dev <<endl;
    rungeKutta_4(&x, &y, &x_dev, &y_dev, h);
  }
  outfile.close();
  int angulos[7] = { 10, 20, 30, 40, 50, 60, 70 }; 
  ofstream outfile2("Angulos.txt");
  for(int i=0; i<7; i++){
	double angulo = angulos[i];
	double h = 0.001;
    double x=0;
    double y=0;
    double t=0;
    double x_dev= 300*cos(angulo*PI/180);
    double y_dev= 300*sin(angulo*PI/180);
    while(y>=0){
    outfile2 << t <<" " << x << " " << y << " " << x_dev << " " << y_dev <<endl;		
	cout << t <<" " << x << " " << y << " " << x_dev << " " << y_dev <<endl;
    rungeKutta_4(&x, &y, &x_dev, &y_dev, h);
  }
  outfile.close();
	return 0;
}
}

