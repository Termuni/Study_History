
/*
순열 공부
https://wonsjung.tistory.com/11

1. 순열이란,

- 순열이란 서로 다른 n개 중에서 r개를 택하여 배열하는 경우를 말한다.

기호로는 nPr로 나타낼 수 있다.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int dep[20];
int n;

void Permutation(int x)
{
    if (x == n)     //종료조건
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", dep[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        dep[x] = i + 1;
        Permutation(x + 1);
    }
}

int main()
{
    scanf("%d", &n);
    Permutation(0);

    return 0;
}
