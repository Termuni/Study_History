//https://www.acmicpc.net/problem/1260

#define LIMIT 1001
#include <stdio.h>

int n, m, v;
int node[LIMIT][LIMIT];
char visited[LIMIT];

void Set_Visit_False();
void Set_Node_Zero();

void Init()
{
    Set_Visit_False();
    Set_Node_Zero();
}
void Set_Visit_False()
{
    for(int i=0; i<LIMIT; ++i)
    {
        visited[i] = '0';
    }
}
void Set_Node_Zero()
{
    for(int i=0; i<LIMIT; ++i)
    {
        for(int j=0; j<LIMIT; ++j)
        {
            node[i][j] = 0;
        }
    }
}
void Get_Node_Connection()
{
    for(int i=0; i<m; ++i)
    {
        int node1, node2;
        scanf("%d %d", &node1, &node2);
        node[node1][node2] = 1;
        node[node2][node1] = 1;
    }
}

void DFS(int now_node)
{
    if(visited[now_node] == '1')
    {
        return;
    }
    printf("%d ", now_node);
    visited[now_node] = '1';
    for(int i=0; i<LIMIT; ++i)
    {
        if(node[now_node][i] == 1)
        {
            DFS(i);
        }
    }
}

// void BFS() // 틀림
// {
//     int index = v;
//     visited[index] = '1';
//     char skip = '0';
//     printf("%d ", index);
//     do
//     {
//         skip = '0';
//         int small = LIMIT;
//         for(int i=0; i<LIMIT; ++i)
//         {
//             if(node[index][i] == 1 && visited[i] != '1')
//             {
//                 skip = '1';
//                 visited[i] = '1';
//                 small = (small > i) ? i : small;
//                 printf("%d ", i);
//             }
//         }
//         index = small;
//     } while(skip != '0');
// }
void BFS()
{
    int list[LIMIT];  // 방문할 노드 리스트 (큐 대신 사용)
    int start = 0, end = 0;  // 리스트의 시작과 끝을 나타내는 인덱스

    list[end++] = v;  // 시작 노드를 리스트에 추가
    visited[v] = '1';

    while (start < end)  // 리스트가 빌 때까지 반복
    {
        int now_node = list[start++];  // 리스트의 앞에서부터 꺼냄
        printf("%d ", now_node);

        for (int i = 1; i <= n; i++)  // 노드는 1부터 n까지 순회
        {
            if (node[now_node][i] == 1 && visited[i] == '0')
            {
                visited[i] = '1';
                list[end++] = i;  // 리스트의 끝에 추가
            }
        }
    }
}


int main()
{
    scanf("%d %d %d", &n, &m, &v);
    
    Init();

    Get_Node_Connection();

    DFS(v);
    puts("");

    Set_Visit_False();

    BFS();
}