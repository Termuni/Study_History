#include<stdio.h>

#define N 5

int main(){
    int a[N];
    for(int i = 0; i<N; ++i){
        printf("a[%d] : ", i);
        scanf("%d", &a[i]);
    }
    puts("�� ����� ��");
    for(int i=0; i<N; ++i){
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("�迭 a�� ��� ������ %d�Դϴ�.\n", sizeof(a)/sizeof(a[0]));
    return 0;
}