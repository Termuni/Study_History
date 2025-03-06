#include<stdio.h>

#define N 5

int main(){
    int a[N];
    for(int i = 0; i<N; ++i){
        printf("a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    puts("각 요소의 값");
    for(int i=0; i<N; ++i){
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("배열 a의 요소 개수는 %d입니다.\n", sizeof(a)/sizeof(a[0]));
    return 0;
}