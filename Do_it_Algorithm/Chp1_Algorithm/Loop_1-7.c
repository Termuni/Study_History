#include<stdio.h>

int main(){
    int n;
    puts("1���� n������ ������ ���մϴ�.");
    printf("n�� : ");
    scanf("%d", &n);
    int sum = 0;
    int i = 1;
    while(i<=n){
        sum += i;
        i++;
    }
    printf("1���� %d������ �� ���� %d�Դϴ�.\n", n, sum);
    return 0;
}