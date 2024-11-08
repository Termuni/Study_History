// https://school.programmers.co.kr/learn/courses/30/lessons/1844

#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    START
} Direction;

// 상, 하, 좌, 우
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

#pragma region DFS
int Move(vector<vector<int>>* maps, vector<vector<bool>>& visited, 
         pair<int, int> pos, pair<int, int>* target, 
         int dist, Direction dir) 
{
    if (pos.first == target->first && pos.second == target->second) {
        // 종료 조건: 목적지 도달
        return dist;
    }

    int min_dist = -1;
    
    // 네 방향으로 이동 시도
    for (int d = 0; d < 4; ++d) {
        int newY = pos.first + dy[d];
        int newX = pos.second + dx[d];
        
        // 경계 검사
        if (newY >= 0 && newY < maps->size() && 
            newX >= 0 && newX < (*maps)[0].size() && 
            !visited[newY][newX] && (*maps)[newY][newX] == 1) 
        {
            visited[newY][newX] = true; // 방문 표시
            int result = Move(maps, visited, make_pair(newY, newX), target, dist + 1, static_cast<Direction>(d));
            visited[newY][newX] = false; // 백트래킹: 방문 취소

            if (result != -1) {
                if (min_dist == -1 || result < min_dist) {
                    min_dist = result;
                }
            }
        }
    }

    return min_dist;
}

int solution_dfs(vector<vector<int>> maps) 
{
    pair<int, int> pos = make_pair(0, 0); // 시작 위치
    pair<int, int> target_point = make_pair(maps.size() - 1, maps[0].size() - 1); // 목적지
    vector<vector<bool>> visited(maps.size(), vector<bool>(maps[0].size(), false));
    visited[0][0] = true; // 시작 위치 방문 표시

    int answer = Move(&maps, visited, pos, &target_point, 1, START);
    return answer;
}
#pragma endregion DFS

#pragma region BFS
int solution_bfs(vector<vector<int>> maps) {
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    queue<pair<pair<int, int>, int>> q; // (현재 위치, 거리)
    q.push({{0, 0}, 1});
    visited[0][0] = true;

    while (!q.empty()) {
        pair<int, int> pos = q.front().first;
        int dist = q.front().second;
        q.pop();

        // 목적지에 도달한 경우
        if (pos.first == n - 1 && pos.second == m - 1) {
            return dist;
        }

        // 네 방향으로 탐색
        for (int i = 0; i < 4; ++i) {
            int newY = pos.first + dy[i];
            int newX = pos.second + dx[i];

            // 경계 검사 및 방문 여부 확인
            if (newY >= 0 && newY < n && newX >= 0 && newX < m && 
                !visited[newY][newX] && maps[newY][newX] == 1) {
                visited[newY][newX] = true;
                q.push({{newY, newX}, dist + 1});
            }
        }
    }

    // 경로가 없는 경우
    return -1;
}
#pragma endregion BFS

int main() 
{
    vector<vector<int>> map = {
        {1, 0, 1, 1, 1}, 
        {1, 0, 1, 0, 1}, 
        {1, 0, 1, 1, 1}, 
        {1, 1, 1, 0, 1}, 
        {0, 0, 0, 0, 1}};
    cout << solution_dfs(map) << endl;
    cout << solution_bfs(map) << endl;
}
