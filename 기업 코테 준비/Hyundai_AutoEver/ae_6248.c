#include <stdio.h>
#include <stdbool.h>

#define MAX_N 100000
#define MAX_M 200000

// �׷��� ������ ���� ���� �迭
int edges[MAX_M + 1], next[MAX_M + 1], head[MAX_N + 1], edgeCount;
int rev_edges[MAX_M + 1], rev_next[MAX_M + 1], rev_head[MAX_N + 1], rev_edgeCount;
bool visited1[MAX_N + 1], visited2[MAX_N + 1];
int queue[MAX_N + 1], front, rear;

// ������ �߰��ϴ� �Լ� (������)
void addEdge(int u, int v)
{
    edges[edgeCount] = v;
    next[edgeCount] = head[u];
    head[u] = edgeCount++;
}

// ������ �߰��ϴ� �Լ� (������)
void addRevEdge(int u, int v)
{
    rev_edges[rev_edgeCount] = v;
    rev_next[rev_edgeCount] = rev_head[u];
    rev_head[u] = rev_edgeCount++;
}

// BFS Ž�� �Լ�
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

    // �׷��� �ʱ�ȭ
    for (int i = 1; i <= n; i++)
    {
        head[i] = -1;
        rev_head[i] = -1;
    }

    // �Է� �ޱ� �� ���� �߰�
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);    // ������ �׷���
        addRevEdge(v, u); // ������ �׷���
    }

    // BFS ����
    bfs(S, visited1, head, edges, next);             // S���� T�� ���� ��� ã��
    bfs(T, visited2, rev_head, rev_edges, rev_next); // T���� S�� ���� ��� ã��

    // ��� ���
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (visited1[i] && visited2[i])
            count++;
    }

    printf("%d\n", count);
    return 0;
}
