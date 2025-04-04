#include<stdio.h>

void Print()
{
    printf("WOWOW");
}

int main()
{
    int target = 0;
    int * point;
    printf("TARGET : %d\n", target);
    printf("POINT without * : %d\n", point);
    printf("POINT with * : %d\n", *point);
    point = &target;
    printf("POINT without * : %d\n", point);
    printf("POINT with * : %d\n", *point);

    void (*function_pointer)();
    function_pointer = Print;
    function_pointer();
}