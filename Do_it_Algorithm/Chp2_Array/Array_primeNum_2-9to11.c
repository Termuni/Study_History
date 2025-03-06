#include<stdio.h>
#include<stdlib.h>

#define TARGET 1000

unsigned long v1(int a[]){
    unsigned long counter = 0;
    int pNp = 0;        //prime number position
    for (int n = 2; n <= TARGET; ++n)
    {
        int i;
        for(i=2; i<n; ++i){
            ++counter;
            if(n%i == 0){
                break;
            }
        }
        if(i==n){
            a[pNp] = n;
            pNp++;
        }
    }
    
    return counter;
}

unsigned long v2(int prime[]){

}

int main()
{
    int *ver1 = calloc(TARGET, sizeof(int));
    int ver2[TARGET];

    printf("Count of seperation: %lu\n", v1(ver1));
    printf("Count of seperation: %lu\n", v2(ver2));
    printf("Prime Numbers: ");
    for(int i = 0; i < TARGET; ++i)
    {
        if (ver1[i] == NULL)
            break;
        printf(" %d", ver1[i]);
    }
}
