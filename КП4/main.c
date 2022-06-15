#include <stdio.h>
#include <math.h>

double functionfornewton(double x){
    return exp(x) + log(x) - 10.0 * x;
}
double DerivativeNewton(double x){
    return exp(x) + (1.0 / x) - 10.0;
}
double functionfordih(double x){
    return cos(x) - exp(-(pow(x,2.0)/2.0)) + x - 1;
}
double functionforiter(double x){
    return 1 + sin(x) - log(1+x);
}
double newtonmethod(double (*Func)(double), double (*FuncDerivative)(double), double a, double b, double eps){
    a=(a+b)/2.0;
    while(fabs(a - b) > eps){
        b = a;
        a = b - Func(b)/FuncDerivative(b);
    }
    return a;
}
double Newton2(double x){
    return x - functionfornewton(x)/DerivativeNewton(x);
}
double dichtmethod(double (*Func)(double), double a, double b, double eps){
    double x;
    while(b-a > eps){
        x = (a+b) / 2.0;
        if(Func(a) * Func(x) < 0){
            b=x;
        }else{
            a=x;
        }
    }
    return x;
}
double itermethod(double (*Func)(double), double a, double b, double eps){
    a=(a+b)/2.0;
    while(fabs(a - b) > eps){
        b = a;
        a = Func(b);
    }
    return a;
}


int main(){
    double eps = 10e-10, a1 = 3.0, b1 = 4.0, a2 = 1.0, b2 = 2.0, a3 = 1.0, b3 = 1.5;
    printf("Метод Ньютона:  %.4f", newtonmethod(&functionfornewton, &DerivativeNewton, a1, b1, eps));
    printf("\nМетод дихтомии: %.4f", dichtmethod(&functionfordih, a2, b2, eps));
    printf("\nМетод итераций: %.4f", itermethod(&functionforiter, a3, b3, eps));
}