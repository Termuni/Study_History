#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_M 200000

// 그래프 저장을 위한 정적 배열
int edges[MAX_M + 1], next[MAX_M + 1], head[MAX_N + 1], edgeCount;
int rev_edges[MAX_M + 1], rev_next[MAX_M + 1], rev_head[MAX_N + 1], rev_edgeCount;
bool visited1[MAX_N + 1], visited2[MAX_N + 1];
int queue[MAX_N + 1], front, rear;

// 간선을 추가하는 함수 (정방향)
void addEdge(int u, int v)
{
    edges[edgeCount] = v;
    next[edgeCount] = head[u];
    head[u] = edgeCount++;
}

// 간선을 추가하는 함수 (역방향)
void addRevEdge(int u, int v)
{
    rev_edges[rev_edgeCount] = v;
    rev_next[rev_edgeCount] = rev_head[u];
    rev_head[u] = rev_edgeCount++;
}

// BFS 탐색 함수
void bfs(int start, bool *visited, int *graphHead, int *graphEdges, int *graphNext)
{
    front = rear = 0;
    queue[rear++] = start;
    visited[start] = true;

    while (front < rear)
    {
        int cur = queue[front++];
        for (int i = graphHead[cur]; i != -1; i = graphNext[i])
        {
            int next = graphEdges[i];
            if (!visited[next])
            {
                visited[next] = true;
                queue[rear++] = next;
            }
        }
    }
}

int main()
{
    int n, m, S, T;
    scanf("%d %d", &n, &m);
    scanf("%d %d", &S, &T);

    // 그래프 초기화
    for (int i = 1; i <= n; i++)
    {
        head[i] = -1;
        rev_head[i] = -1;
    }

    // 입력 받기 및 간선 추가
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);    // 정방향 그래프
        addRevEdge(v, u); // 역방향 그래프
    }

    // BFS 수행
    bfs(S, visited1, head, edges, next);             // S에서 T로 가는 경로 찾기
    bfs(T, visited2, rev_head, rev_edges, rev_next); // T에서 S로 가는 경로 찾기

    // 결과 계산
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited1[i] && visited2[i])
            count++;
    }

    printf("%d\n", count);
    return 0;
}
