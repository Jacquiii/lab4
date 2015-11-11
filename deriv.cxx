#include <iostream>
#include <cmath>

using namespace std;


void print(double* p, const int N, const double dx,
           const double xmin)
{
   for(int i=0; i<N; i++){    
     cout << i*dx + xmin << "\t" << p[i] << endl;
   }
}

void Wolf(double* p, const int N, const double dx,
           const double xmin)
{
    for(int i=0; i<N; i++){
        p[i]=exp(-(i*dx + xmin)*(i*dx + xmin));
    }
}
void henry(double* p, const int N, const double dx,
           const double xmin)
{
  double p1,p0=0;
  
  for(int i=0; i<N-1; i++){
    p1=p[i];
    p[i]=(p[i+1]-p0)/(2*dx);
    p0=p1; 
  }
  p[N-1]=p0/(2*dx);
}


int main(){
  const int N = 256;
  double p[N];
  const double xmax = 15;
  const double xmin = -15;
  const double dx = (xmax-xmin)/(N-1);
  

  // call to function which fills array p here
  // call to functio which calculates the derivative

  Wolf(p,N,dx,xmin);
  henry(p,N,dx,xmin);
  print(p,N,dx,xmin);

  return 0;
}
