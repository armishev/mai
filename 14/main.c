#include <stdio.h>

enum { maxn = 100 };

int main(){
    int m[maxn] [maxn];
    int n;
    scanf("%i",&n);
    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            scanf("%d", &m[i] [j]);
    int i0 = n-1, j0 = n-1;
    int state = 1;
    int flag =1;
    int flag2;
    while(flag){
        switch(state){
            case 1:
                if (i0 == n - 1 && j0 == n - 1) {
                    printf("%d ", m[i0][j0]);
                    i0 -= 1;
                    state = 2;
                }
                break;
            case 2:
                if (i0 == n - 1 && j0 != 0) {
                    printf("%d ", m[i0][j0]);
                    j0 -= 1;
                    state = 3;
                } else if (i0 == n - 1 && j0 == 0) {
                    printf("%d ", m[i0][j0]);
                    i0 -= 1;
                    flag2=0;
                    state = 4;
                } else if (i0 != n - 1) {
                    printf("%d ", m[i0][j0]);
                    i0 += 1;
                    j0 -= 1;
                    state = 2;
                }
                break;
            case 3:
                if (j0 == n - 1) {
                    printf("%d ", m[i0][j0]);
                    i0 -= 1;
                    state = 2;
                } else if (i0 == n-1 && j0 == 0) {
                    flag2=1;
                    state = 4;
                } else if(j0 != n - 1) {
                    printf("%d ", m[i0][j0]);
                    i0-=1;
                    j0+=1;
                }
                break;
            case 4:
                if(flag2==0) {
                    if (i0 == 0) {
                        printf("%d ", m[i0][j0]);
                        j0 -= 1;
                        state = 5;
                    } else if (i0 != 0) {
                        printf("%d ", m[i0][j0]);
                        i0 -= 1;
                        j0 += 1;
                        state = 4;
                    }
                };
                if(flag2==1) {
                    if (i0 == 0) {
                        printf("%d ", m[i0][j0]);
                        j0 -= 1;
                        state = 5;
                    } else if (i0 != 0) {
                        printf("%d ", m[i0][j0]);
                        i0 -= 1;
                        j0 += 1;
                        state = 4;
                    }
                };
                break;
            case 5:
                if(flag2==0){
                    if (j0 == 0 && i0 == 0) {
                        printf("%d ", m[i0][j0]);
                        flag = 0;
                    } else if (j0 == 0 && i0 != 0) {
                        printf("%d ", m[i0][j0]);
                        i0 -= 1;
                        state = 5;
                    } else if (j0 != 0) {
                        printf("%d ", m[i0][j0]);
                        i0 += 1;
                        j0 -= 1;
                        state = 5;
                    }
                };
                if(flag2==1){
                    if (j0 == 0 && i0 == 0) {
                        printf("%d ", m[i0][j0]);
                        flag = 0;
                    } else if (j0 == 0 && i0 != 0) {
                        printf("%d ", m[i0][j0]);
                        i0 -= 1;
                        state = 5;
                    } else if (j0 != 0) {
                        printf("%d ", m[i0][j0]);
                        i0 += 1;
                        j0 -= 1;
                        state = 5;
                    }
                }
                break;
    }
    }
    putchar('\n');


}
