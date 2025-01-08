#include<stdio.h>
#include<stdlib.h>

int main(){
    int na;
    printf("요소개수 : ");
    scanf("%d", &na);

    int *a = calloc(na, sizeof(int));

    if(a==NULL){
        puts("메모리 확보에 실패했습니다.\n");
    }
    else{
        printf("%d개 정수를 입력하세요.\n", na);
        for(int i=0; i<na; ++i){
            printf("a[%d]: ", i);
            scanf("%d",&a[i]);
        }
        printf("각 요솟값은 아래와 같습니다.\n");
        for(int i=0; i<na; ++i){
            printf("a[%d] = %d\n", i, a[i]);
        }
        free(a);
    }
    return 0;
}