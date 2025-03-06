#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int N, M;
int arr[20];

void Mixture(int index, int start)
{
    if (index == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = start; i <= N; i++)
    {
        arr[index] = i;
        Mixture(index + 1, i + 1);
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    Mixture(0, 1);
    return 0;
}
