#define MAXNUM 1e+10
#define TRUE '1'
#define FALSE '0'
#include<stdio.h>

int num1, num2, count;
char numbers[10];

void Init();
void Reset_Numbers();
void Set_Numbers(int target1, int target2);
char Checking(int target);
void Downgrading(int target);

void Init()
{
    count = 0;
    Reset_Numbers();
}

void Reset_Numbers()
{
    for(int i=0; i<10; ++i)
    {
        numbers[i] = FALSE;
    }
}

void Downgrading(int target)
{
    while(target > 0)
    {
        int temp = target%10;
        numbers[temp] = TRUE;
        target /= 10;
    }
}

void Set_Numbers(int target1, int target2)
{
    Downgrading(target1);
    Downgrading(target2);
}

char Checking(int target)
{
    while(target>0)
    {
        int temp = target % 10;
        if(numbers[temp] == FALSE)
        {
            return FALSE;
        }
        target /= 10;
    }
    return TRUE;
}

int main()
{
    Init();

    scanf("%d %d", &num1, &num2);

    for(int i=1; i<=num1; ++i)
    {
        for(int j=1; j<=num2; ++j)
        {
            Reset_Numbers();
            Set_Numbers(i, j);
            count = (Checking(i*j) == TRUE) ? count+1 : count;
        }
    }

    printf("%d", count);
    return 0;
}