#include<stdio.h>
#include<stdlib.h>

int main(){
    int *x = calloc(1, sizeof(int));
    if(x==NULL){
        puts("�޸� �Ҵ翡 �����߽��ϴ�.\n");
    }
    else{
        *x=57;
        printf("*x = %d\n", *x);
        free(x);
    }
    return 0;
}