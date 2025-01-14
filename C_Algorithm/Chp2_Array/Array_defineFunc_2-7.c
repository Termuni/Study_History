#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define swap(type, x, y) do{ type t = x; x = y; y = t;}while(0)

void ary_reverse(int a[], int n){
    for(int i=0; i<n/2; ++i){
        swap(int, a[i], a[n-i-1]);
    }
}

int main(){
    srand(time(NULL));
    int nx;
    printf("array numbers: ");
    scanf("%d", &nx);
    int *x = calloc(nx, sizeof(int));
    for(int i=0; i<nx; ++i){
        x[i] = rand() % 10;
        printf("x[%d]: %d\n", i, x[i]);
    }
    ary_reverse(x, nx);
    printf("Array has been reversed.\n");
    for(int i=0; i<nx; ++i){
        printf("x[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;

}