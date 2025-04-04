//https://www.acmicpc.net/problem/1303
/*
5 5
WBWWW
WWWWW
BBBBB
BBBWW
WWWWW

W -> 9*9 + 7*7 = 81+49 = 130
B -> 1*1 + 8*8 = 1+64 = 65
*/
#include <stdio.h>

#define LIMIT 101

int n, m;
int w = 0, b = 0;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

char war[LIMIT][LIMIT];
char check[LIMIT][LIMIT];

void Init()
{
    for (int i = 0; i < LIMIT; ++i)
    {
        for (int j = 0; j < LIMIT; ++j)
        {
            war[i][j] = '0';
            check[i][j] = '0';
        }
    }
}

void Get_Input()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        scanf("%s", war[i]);
    }
}

void Print_Check()
{
    for(int i=0; i<m; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            printf("%c",check[i][j]);
        }
        puts("");    
    }
}

int DFS(char solider, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (check[y][x] == '1' || war[y][x] != solider) return 0;

    check[y][x] = '1';
    int size = 1;

    for (int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        size += DFS(solider, nx, ny);
    }
    return size;
}

int main()
{
    Init();
    Get_Input();

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (check[i][j] == '0')
            {
                char solider = war[i][j];
                int power = DFS(solider, j, i);
                if (solider == 'W') {w += power * power; Print_Check();}
                else if (solider == 'B') {b += power * power; Print_Check();}
            }
        }
    }

    printf("%d %d\n", w, b);
    return 0;
}
