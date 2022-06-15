#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int sign(int x)
{
    return (x > 0) - (x < 0);
}

int incircle1(double x, double y)
{
    return pow(x-10,2) + pow(y-10,2) <= pow(5, 2);
}

int incircle2(double x, double y)
{
    return pow(x-10,2) + pow(y-10,2) <= pow(10, 2);
}

struct point{
    int i;
    int j;
    int l;
};

int in_ring(struct point p)
{
    return incircle2(p.i, p.j) && !incircle1(p.i, p.j);
}

int change_i(int i, int j, int l, int k)
{
    return max(j-k,l-k) % 30 + max(i+l,j+k) % 20;
}

int change_j(int i, int j, int l, int k)
{
    return (abs(i-l) * sign(j+k) + abs(i-k)*(j+k)) % 20;
}

int change_l(int i, int j, int l, int k)
{
    return ((i+k)*(j-k)*(l+k)) % 25;
}

struct point0 {
    int i;
    int j;
    int l;
};

struct point change(struct point p, int k)
{
    struct point0 p0;
    p0.i=p.i; p0.j=p.j; p0.l=p.l;
    p.i = change_i(p0.i, p0.j ,p0.l ,k);
    p.j = change_j(p0.i, p0.j ,p0.l ,k);
    p.l = change_l(p0.i, p0.j ,p0.l ,k);
    return p;
}

int main(void)
{
    int k;
    
    
    struct point p = {.i=-1, .j=-1, .l=-9};

    for (k=1; !in_ring(p) && k < 50; ++k){
        p = change(p, k);
        
    }
    
    in_ring(p) ? printf("Inside\n") : printf("Outside\n");
    printf("i = %d, j = %d, k = %d, l = %d\n", p.i, p.j, k, p.l);
    
    return 0;
}