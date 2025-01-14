#include<stdio.h>

int main(){
    int n;
    puts("1부터 n까지의 총합을 구합니다.");
    printf("n값 : ");
    scanf("%d", &n);
    int sum = 0;
    int i = 1;
    while(i<=n){
        sum += i;
        i++;
    }
    printf("1부터 %d까지의 총 합은 %d입니다.\n", n, sum);
    return 0;
}