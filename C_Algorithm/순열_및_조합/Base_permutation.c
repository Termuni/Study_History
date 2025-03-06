
/*
���� ����
https://wonsjung.tistory.com/11

1. �����̶�,

- �����̶� ���� �ٸ� n�� �߿��� r���� ���Ͽ� �迭�ϴ� ��츦 ���Ѵ�.

��ȣ�δ� nPr�� ��Ÿ�� �� �ִ�.

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
    if (x == n)     //��������
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
