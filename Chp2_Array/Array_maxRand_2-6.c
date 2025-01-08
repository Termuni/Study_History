#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int maxof(const int a[], int n){
    int max = a[0];
    for(int i=1; i<n; ++i){
        if(a[i]>max) max = a[i];
    }
    return max;
}

int main(){
    int number;
    printf("사람 수 : ");
    scanf("%d", &number);
    int *height = calloc(number, sizeof(int));
    
    srand(time(NULL));      //시간으로 난수 시드를 초기화

    for(int i=0; i<number; ++i){
        height[i] = 100 + rand() % 90;              //100 ~ 189 난수 생성, 대입
        printf("height[%d] = %d\n", i, height[i]);
    }

    printf("최댓값은 %d입니다.\n", maxof(height, number));

    free(height);

    return 0;
}