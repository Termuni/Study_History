#include <stdio.h>

int main(void)
{
    unsigned long long k, p;
    int n;
    scanf("%llu %llu %d", &k, &p, &n);
    // printf("%llu %llu %d", k, p, n);

    for (int i = 0; i < n; ++i)
    {
        k *= p;
        k %= 1000000007;
    }

    printf("%llu", k);

    return 0;
}