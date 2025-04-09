//https://www.acmicpc.net/problem/2178

#define MINIMUM 2
#define MAXIMUM 101

#include <stdio.h>

int n, m;
char maze[MAXIMUM][MAXIMUM];

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i)
    {
        scanf("%s", maze[i]);
    }
}