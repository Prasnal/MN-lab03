#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>

#define SIZE 500

using namespace std;

int main(){
  double dx=0.01;
  int n=SIZE;
  double alfa=1;
  double beta=3;
  double x[n+1];
   x[0]=0;
  //inicjalizacja wektoru b:
  
  double b[n+1];
  for(int i=1; i<n+1; i++){
    x[i]=i*dx;
    b[i]=beta*x[i]*pow(dx,2);
  }
  b[0]=0;
  b[n]=0;
  //inicjalizacja wektorow:
  double d[n+1];
  double u[n+1];
  double l[n+1];

  for(int i=0; i<n+1; i++){
    d[i]=-2;
    u[i]=1+alfa*dx;
    l[i]=1-alfa*dx;
  }
  d[0]=1;
  d[n]=1;
  u[0]=0;
  u[n]=0;
  l[0]=0;
  l[n]=0;
  double tmp[n+1];
  //metoda jacobiego:
  double Tn[n+1];
  double Ts[n+1];
  Ts[0]=0;
  Ts[n]=0;
  //Ts[2]=0;
  int j=0;
  double r[n];
  r[0]=0;
  //float wektor[n+1];
  double norma;
  do{
  for(int k=1; k<n; k++){
    //tmp[k]=Tn[k];
    //Tn[k]=Ts[k];
    Ts[k]=Tn[k];
    //cout<<Ts[k]<<endl;
  }
  Tn[0]=0;
  Ts[0]=0;
  Tn[n]=0;
  Ts[n]=0;
  for(int i=1; i<n; i++){   
    Tn[i]=1/d[i]*(b[i]-u[i]*Ts[i+1]-l[i]*Ts[i-1]);
    //Tn[i]=1/d[i]*(b[i]-u[i]*Ts[i+1]-l[i]*Tn[i-1]);
  }
  norma=0;
  for (int z=0; z<n; z++){
    norma+=pow(Ts[z]-Tn[z],2);
  }
  j++;

  }while((abs(sqrt(norma))>pow(10,-5)));

    
  for(int g=1; g<n; g++){
    r[g]=b[g]-l[g]*Tn[g-1]-u[g]*Tn[g+1]-d[g]*Tn[g];
  }

  //zapisywanie do pliku
  FILE *fa=fopen("dane.dat","w");
  for(int i=0; i<n+1; i++){
      fprintf(fa," %f %f \n",dx*i, Tn[i]);
    }

  FILE *fb=fopen("dane2.dat","w");
  for(int i=0; i<n; i++){
    cout<<dx*i<<" "<<r[i]<<endl;
    fprintf(fb," %f %f \n",dx*i, r[i]);
  }


  FILE *fc=fopen("dane3.dat","w");
  fprintf(fc," %d \n",j);


  fclose(fa);
  fclose(fb);
  fclose(fc);
  

return 0;

}
