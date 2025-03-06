// 순열 공부
// https://wonsjung.tistory.com/11

// <순열 코드 - 중복허용x>
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

int dep[20];
bool visited[20];
int n;

void Permutation(int x)
{
    if (x == n)
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
        if (!visited[i + 1])
        {
            dep[x] = i + 1;
            visited[i + 1] = true;
            Permutation(x + 1);
            visited[i + 1] = false;
        }
    }
}

int main()
{
    scanf("%d", &n);
    Permutation(0);
    return 0;
}