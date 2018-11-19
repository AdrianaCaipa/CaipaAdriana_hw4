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
int tamanio=50;
double dx = 0.001;
double dy = 0.001;
double dt = dx/v*0.0001;
double presente[tamanio][tamanio];
double futuro[tamanio][tamanio];
double meanpresente=0;
double meanfuturo=0;
int total=0;
 
for(int i=0; i<tamanio;i++){
    for(int j=0; j<tamanio; j++){
        if(((i-25.0)*(i-25.0)+(j-25.0)*(j-25.0))<(5.0*5.0)){
            presente[i][j]=100;
         }
     else {
        presente[i][j]=10;
        total +=1;
        meanpresente += presente[i][j];
     }
    }  
    }
      meanpresente = meanpresente/total;
     // cout << meanpresente << endl;
     //cout << total << endl;
ofstream outfile1("promedio_f.txt");
ofstream outfile2("Temperatura_f.txt");
ofstream outfile3("promedio_p.txt");
ofstream outfile4("Temperatura_p.txt");
ofstream outfile5("promedio_l.txt");
ofstream outfile6("Temperatura_l.txt");
for(;;){
    meanfuturo = 0;
    for(int i=0; i<tamanio;i++){
        for(int j=0; j<tamanio; j++){
    if(((i-25.0)*(i-25.0)+(j-25.0)*(j-25.0))<(5.0*5.0)){
    futuro[i][j]=100;
    }
    else {
        futuro[i][j]=presente[i][j]+ (((v*dt)/(dx*dx))*(presente[i+1][j]-2*presente[i][j]+presente[i-1][j])+ ((v*dt)/(dy*dy)* (presente[i][j+1]-2*presente[i][j]+presente[i][j-1])));
    
    futuro[0][j]=10; //Condiciones de frontera
    futuro[49][j]=10;
    futuro[i][0]=10;
    futuro[i][49]=10;
 
    meanfuturo += futuro[i][j]/total;
    //cout << meanfuturo<<endl;
       }
//cout << futuro[i][j] << " ";
     }  
//cout << endl;
}
   outfile1 << meanfuturo<< endl;
       if(abs(meanfuturo-meanpresente)<0.01){
           break;
        }
    meanpresente = 0;
    for(int i=0; i<tamanio;i++){
        for(int j=0; j<tamanio; j++){
        if(((i-25.0)*(i-25.0)+(j-25.0)*(j-25.0))<(5.0*5.0)){
        presente[i][j]=100;
    }
             else {
                 presente[i][j]=futuro[i][j];
                 meanpresente += presente[i][j]/total;
		     
    }
	outfile2<<presente[i][j]<<" ";
}
// meanpresente = meanfuturo;   
 	outfile2<<endl;
    }
 
}
 
//////############FronterasAbiertas###########/////


for(int i=0; i<tamanio;i++){
    for(int j=0; j<tamanio; j++){
        if(((i-25.0)*(i-25.0)+(j-25.0)*(j-25.0))<(5.0*5.0)){
            presente[i][j]=100;
         }
     else {
        presente[i][j]=10;
        meanpresente += presente[i][j];
     }
                           }  
                              }
      meanpresente = meanpresente/total;
cout << meanpresente << endl;
cout << total << endl;

cout << endl;
cout << endl;
cout << endl;
cout << endl;


for(;;){
    meanfuturo = 0;
    for(int i=0; i<tamanio;i++){
        for(int j=0; j<tamanio; j++){
    if(((i-25.0)*(i-25.0)+(j-25.0)*(j-25.0))<(5.0*5.0)){
    futuro[i][j]=100;
    }
    else {
        futuro[i][j]=presente[i][j]+ (((v*dt)/(dx*dx))*(presente[i+1][j]-2*presente[i][j]+presente[i-1][j])+ ((v*dt)/(dy*dy)* (presente[i][j+1]-2*presente[i][j]+presente[i][j-1])));
    
    futuro[0][j]=futuro[1][j]; //Condiciones de frontera abierta
    futuro[49][j]=futuro[48][j];
    futuro[i][0]=futuro[i][1];
    futuro[i][49]=futuro[i][48];
 
    meanfuturo += futuro[i][j]/total;
//   cout << meanfuturo<<endl;
       }
//cout << futuro[i][j] << " ";
     }  
//cout << endl;
}
    outfile3 << meanfuturo<< endl;
       if(abs(meanfuturo-meanpresente)<0.001){
           break;
        }
    meanpresente = 0;
    for(int i=0; i<tamanio;i++){
        for(int j=0; j<tamanio; j++){
        if(((i-25.0)*(i-25.0)+(j-25.0)*(j-25.0))<(5.0*5.0)){
        presente[i][j]=100;
    }
             else {
                 presente[i][j]=futuro[i][j];
                 meanpresente += presente[i][j]/total;     
    }
	outfile4<<presente[i][j]<<" ";
}
// meanpresente = meanfuturo;   
 	outfile4<<endl;
    }
 
}
//////############FronterasPeriodicas###########/////

for(int i=0; i<tamanio;i++){
    for(int j=0; j<tamanio; j++){
        if(((i-25.0)*(i-25.0)+(j-25.0)*(j-25.0))<(5.0*5.0)){
            presente[i][j]=100;
         }
     else {
        presente[i][j]=10;
        meanpresente += presente[i][j];
     }
                           }  
                              }
      meanpresente = meanpresente/total;
cout << meanpresente << endl;
cout << total << endl;

cout << endl;

cout << endl;
cout << endl;
cout << endl;


for(;;){
    meanfuturo = 0;
    for(int i=0; i<tamanio;i++){
        for(int j=0; j<tamanio; j++){
    if(((i-25.0)*(i-25.0)+(j-25.0)*(j-25.0))<(5.0*5.0)){
    futuro[i][j]=100;
    }
    else {
        futuro[i][j]=presente[i][j]+ (((v*dt)/(dx*dx))*(presente[i+1][j]-2*presente[i][j]+presente[i-1][j])+ ((v*dt)/(dy*dy)* (presente[i][j+1]-2*presente[i][j]+presente[i][j-1])));
    
    futuro[0][j]=futuro[48][j]; //Condiciones de frontera abierta
    futuro[49][j]=futuro[1][j];
    futuro[i][0]=futuro[i][48];
    futuro[i][49]=futuro[i][1];
 
    meanfuturo += futuro[i][j]/total;
//   cout << meanfuturo<<endl;
       }
//cout << futuro[i][j] << " ";
     }  
//cout << endl;
}
    outfile5 << meanfuturo<< " ";
       if(abs(meanfuturo-meanpresente)<0.001){
           break;
        }
    meanpresente = 0;
    for(int i=0; i<tamanio;i++){
        for(int j=0; j<tamanio; j++){
        if(((i-25.0)*(i-25.0)+(j-25.0)*(j-25.0))<(5.0*5.0)){
        presente[i][j]=100;
    }
             else {
                 presente[i][j]=futuro[i][j];
                 meanpresente += presente[i][j]/total;     
    }
}
// meanpresente = meanfuturo;   
 
    }
 }
return 0;
}
