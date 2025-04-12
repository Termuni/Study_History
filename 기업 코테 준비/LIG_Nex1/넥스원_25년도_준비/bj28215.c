#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000
#define MAXIMUM 200000

int houses[MAX_N][2];
int n, k;

int Get_Distance(int p1, int p2, int p3) {
    int ans = 0;
    for (int i = 0; i < n; ++i) 
    {
        int d1 = abs(houses[i][0] - houses[p1][0]) + abs(houses[i][1] - houses[p1][1]);
        int d2 = abs(houses[i][0] - houses[p2][0]) + abs(houses[i][1] - houses[p2][1]);
        int d3 = abs(houses[i][0] - houses[p3][0]) + abs(houses[i][1] - houses[p3][1]);
        int min_dist = d1 < d2 ? (d1 < d3 ? d1 : d3) : (d2 < d3 ? d2 : d3);
        if (ans < min_dist) ans = min_dist;
    }
    return ans;
}

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) 
    {
        scanf("%d %d", &houses[i][0], &houses[i][1]);
    }

    int ans = MAXIMUM;

    if (k == 1) {
        for (int i = 0; i < n; ++i) {
            int d = Get_Distance(i, i, i);
            if (d < ans) ans = d;
        }
    } 
    else if (k == 2) 
    {
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int d = Get_Distance(i, j, j);
                if (d < ans) ans = d;
            }
        }
    } 
    else if (k == 3) 
    {
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int l = j; l < n; ++l) {
                    int d = Get_Distance(i, j, l);
                    if (d < ans) ans = d;
                }
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
