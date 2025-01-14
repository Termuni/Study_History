#define MAX_INT 1e9
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

typedef pair<int, int> Point;
struct State {
    int y, x, used; // 현재 위치 (y, x)와 통과한 0의 횟수
    int dist;       // 시작점으로부터의 거리
};

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> maps, int max_zero_pass) {
    int n = maps.size();
    int m = maps[0].size();

    // 3차원 visited 배열: visited[y][x][k] (k는 통과한 0의 횟수)
    // vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(max_zero_pass + 1, false)));
    vector<vector<vector<int>>> visited(n, vector<vector<int>>(m, vector<int>(max_zero_pass + 1, MAX_INT)));
    
    queue<State> q;
    q.push({0, 0, 0, 1}); // 시작점 (0, 0)에서 시작, 0을 통과한 횟수 0, 거리 1
    
    visited[0][0][0] = 1;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        // 목적지에 도달한 경우
        if (cur.y == n - 1 && cur.x == m - 1) {
            return cur.dist;
        }
        // 네 방향으로 탐색
        for (int i = 0; i < 4; ++i) {
            int newY = cur.y + dy[i];
            int newX = cur.x + dx[i];
            // 경계 검사
            if (newY >= 0 && newY < n && newX >= 0 && newX < m) {
                int next_used = cur.used;
                // 0인 곳을 통과하는 경우
                if (maps[newY][newX] == 0) {
                    next_used++;
                }
                // // 조건: 0 통과 횟수가 max_zero_pass 이하인 경우에만 이동
                // if (next_used <= max_zero_pass && !visited[newY][newX][next_used]) {
                //     visited[newY][newX][next_used] = true;
                //     q.push({newY, newX, next_used, cur.dist + 1});
                // }
                // // 1인 곳은 통과 횟수를 증가시키지 않음
                // if (maps[newY][newX] == 1 && !visited[newY][newX][cur.used]) {
                //     visited[newY][newX][cur.used] = true;
                //     q.push({newY, newX, cur.used, cur.dist + 1});
                // }
                // 탐색할 때, 현재 위치에 도달하는 거리가 기존보다 작으면 갱신
                if (next_used <= max_zero_pass && cur.dist + 1 < visited[newY][newX][next_used]) {
                    cout<<"[x,y] = ["<<newX<<','<<newY<<"] // before visited : "<<visited[newY][newX][next_used]<< " and It would be "<<cur.dist + 1<<'\n';
                    visited[newY][newX][next_used] = cur.dist + 1;
                    q.push({newY, newX, next_used, cur.dist + 1});
                }
            }
        }
    }
    // 경로가 없는 경우
    return -1;
}

int main() {
    vector<vector<int>> map = {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };
    int max_zero_pass = 2; // 최대 2번 0을 통과할 수 있는 조건
    cout << solution(map, max_zero_pass) << endl;
}
