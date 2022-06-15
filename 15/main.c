#include <stdio.h>

enum { maxn = 100 };

int main(void) {
    int n = 0, x = 0, y = 0, i, j, numberminstr, minelementstr=100000, numbermincol, maxelementcol=-100000;
    int a[maxn][maxn];

    scanf("%d", &n);
    for (i = 0; i != n; ++i) {
        for (j = 0; j != n; ++j) {
            scanf("%d", &a[i][j]);
        }
    }
    while (x != n) {
        y=0;
        while (y!= n) {
            if(a[x][y] < minelementstr){
                minelementstr = a[x][y];
                numberminstr = x;
            }
            y+=1;
        }
        x+=1;
    }
    x=0;
    y=0;
    while (y != n) {
        x = 0;
        while (x != n) {
            if (a[x][y] > maxelementcol) {
                maxelementcol = a[x][y];
                numbermincol = y;
            }
            x += 1;
        }
        y += 1;
    }
    for(int i = 0; i<n; i++){
        printf("%d ", a[numberminstr][i]*a[i][numbermincol]);
    }
}