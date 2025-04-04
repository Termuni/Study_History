
#include<stdio.h>

int Get_Age(int age)
{
    return age;
}

void Print_Age(int (*fp)(int), int age) {
	printf("Age is %d\n", fp(age));
}


int main()
{
    int age = 21;
    int (*fp)(int) = Get_Age;	// 함수 포인터 선언과 함께 초기화
    Print_Age(fp, age);
    return 0;
}