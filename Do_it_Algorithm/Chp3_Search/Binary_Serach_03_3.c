#include<stdio.h>
#include<stdlib.h>

int Binary_Search(const int target[], int n, int key)
{
    int pl = 0, pr = n-1;
    do{
        int pc = (pl+pr)/2;
        if(target[pc] == key)
            return pc; 
        else if(target[pc] < key)
            pl = pc + 1;
        else
            pr = pc - 1;
    }while(pl<=pr);
    return -1;
}

int main(void)
{
    int nx, ky;

    //INPUT - DATAS
    printf("number of instruments : ");
    scanf("%d", &nx);

    int *x = (int*)calloc(nx, sizeof(int));
    printf("오름차순으로 입력하세요\n x[0] : ");
    scanf("%d", &x[0]);
    for(int i=1; i<nx; ++i)
    {
        do{
            printf("x[%d]: ",i);
            scanf("%d",&x[i]);
        } while(x[i]<x[i-1]);
    }

    //INPUT - KEY
    printf("검색값 : ");
    scanf("%d",&ky);

    //Search
    int idx = Binary_Search(x, nx, ky);
    if(idx == -1)
        puts("Search Failed");
    else
        printf("%d is in x[%d]\n", ky, idx);
    
    free(x);

    return 0;
}