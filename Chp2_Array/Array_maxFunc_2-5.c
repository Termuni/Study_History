#include<stdio.h>
#include<stdlib.h>

int maxof(const int a[], int n){
    int max = a[0];
    for(int i=1; i<n; ++i){
        if(max < a[i]) max = a[i];
    }
    return max;
}

int main(){
    int number;
    printf("사람 수: ");
    scanf("%d", &number);
    int *height = calloc(number, sizeof(int));
    printf("%d 명의 키를 입력하세요.\n", number);
    for(int i=0; i<number; ++i){
        printf("height[%d]: ", i);
        scanf("%d", &height[i]);
    }
    printf("최댓값은 %d입니다.\n", maxof(height, number));
    //printf("최댓값은 %d입니다.\n", maxof(height, sizeof(height) / sizeof(height[0]))); // 이건 다른값 나옴! 근데 왜 2가 나올까?
    //printf("%d", sizeof(height) / sizeof(height[0]));
    free(height);
    return 0;
}