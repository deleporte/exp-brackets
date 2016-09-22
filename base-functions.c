#include <stdio.h>
#include <math.h>
#include <complex.h>
//testlib.c

double choose(int n, int k){
  if (k>n && k<0){
    return 0;
  }
  else if (k > n/2){
    return choose(n,n-k);
  }
  else if (k == 0){
    return 1;
  }
  else{
    return n*choose(n-1,k-1)/k;
  }    
}

double fact(int n){
  if (n<=0){
      return 0;
  }
  else{
    return n*fact(n-1);
  }
}

double psi(int N,double x, double y, double delta){
  return exp(delta*x*x*N)*exp(delta*y*y*N);
}

double complex e(int N, int k, double x, double y){
  int i;
  double complex result = N*pow(N,(double)k/2.0)/sqrt(fact(N))*psi(N,x,y,-0.5);
  for(i=0; i<k; i++){
    result *= x+y*I;
  }

  return result;
}

double phi(double x){
  if (x<=1){
    return 0;
  }
  else if (x>=2){
    return 1;
  }
  else{
    return exp(-1.0/(x-1))*(1-exp(1/(x-2)));
  }
}

double complex S(int N,double x,double y,double z,double w){
  double complex result = exp(-((x-z)*(x-z)+(y-w)*(y-w))/2*N)*1/N;
  result *= cos((y*z-x*w)*N)+sin((y*z-x*w)*N)*I;
  return result;
}


double realInt(int N, int k, double x, double y, double z, double w, double u, double v, double s, double t, double d){
  return creal(conj(e(N,k,x,y))*S(N,x,y,w,z)*psi(N,x,y,d)*S(N,w,z,u,v)*S(N,u,v,s,t)*(phi(u*u+v*v)*psi(N,s,t,-d)-psi(N,u,v,-d)*phi(s*s+t*t))*e(N,k,s,t));
}

double imagInt(int N, int k, double x, double y, double z, double w, double u, double v, double s, double t, double d){
  return cimag(conj(e(N,k,x,y))*S(N,x,y,w,z)*psi(N,x,y,d)*S(N,w,z,u,v)*S(N,u,v,s,t)*(phi(u*u+v*v)*psi(N,s,t,-d)-psi(N,u,v,-d)*phi(s*s+t*t))*e(N,k,s,t));
}
