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
    printf("��� ��: ");
    scanf("%d", &number);
    int *height = calloc(number, sizeof(int));
    printf("%d ���� Ű�� �Է��ϼ���.\n", number);
    for(int i=0; i<number; ++i){
        printf("height[%d]: ", i);
        scanf("%d", &height[i]);
    }
    printf("�ִ��� %d�Դϴ�.\n", maxof(height, number));
    //printf("�ִ��� %d�Դϴ�.\n", maxof(height, sizeof(height) / sizeof(height[0]))); // �̰� �ٸ��� ����! �ٵ� �� 2�� ���ñ�?
    //printf("%d", sizeof(height) / sizeof(height[0]));
    free(height);
    return 0;
}