#include <stdio.h>
#include <math.h>


double Func(double x){
    return x * (3 - x) / pow((1 - x), 3);
}

double FuncTalor(double x, unsigned p){
    double y = 0;
    for(unsigned i = 1; i <= p; ++i) {
        y += i * (i + 2) * pow(x, i);
    }
    return y;
}
void calculateTalor(double a,double b, unsigned n, double (*Reference)(double), double (*Talor)(double, unsigned)){
    double x = a, i = 0, step;
    double epsilon = 1e-10;
    step = (b - a) / n;
    printf("\n=====================================================================\n");
    printf("|| Шаг\t  x\t     Функция Тейлора           Функция               i  ||\n");
    printf("||------------------------------------------------------------------||\n");
    n = 0;
    while (x <= b){
        int i = 1;
        double currentValueFunc = Reference(x);
        double currentValue = 0, difference = 0;
        currentValue = Talor(x, i);
        difference = currentValueFunc - currentValue;
        while ((difference > epsilon || difference < -epsilon) && i < 100){
            currentValue = Talor(x, i);
            i++;
            difference = currentValueFunc - currentValue;
        };
        printf("||  %d\t %.2f\t %.17f\t %.17f\t %d\t||\n", n, x, currentValue, currentValueFunc, i);
        x += step;
        n++;
    }
    printf("======================================================================\n");
}

int main(){
    float a = 0.0, b = 0.5;
    int n;
    printf("Enter the number of steps: ");
    scanf("%d", &n);
    calculateTalor(a, b, n, &Func, &FuncTalor);
    return 0;
}