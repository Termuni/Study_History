#define INT_MAX 1e9
#include <vector>
#include <queue>
#include <iostream>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> State; // (현재까지의 시간, y, x)

// 네 방향 이동
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int solution(vector<vector<int>> maps, vector<vector<int>> time_costs, int max_zero_pass) {
    int n = maps.size();
    int m = maps[0].size();

    // 3차원 벡터로 visited 배열을 생성하여 (y, x, 0 통과 횟수) 별로 방문 여부 확인
    vector<vector<vector<int>>> min_time(n, vector<vector<int>>(m, vector<int>(max_zero_pass + 1, INT_MAX)));
    
    // 우선순위 큐를 사용하여 최소 시간 기준으로 탐색 (min-heap)
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({0, 0, 0}); // 시작점에서 (시간 0, y=0, x=0)
    min_time[0][0][0] = 0;

    while (!pq.empty()) {
        int cur_time = std::get<0>(pq.top());
        int y = std::get<1>(pq.top());
        int x = std::get<2>(pq.top());
        pq.pop();

        // 목적지에 도달한 경우 최소 시간 반환
        if (y == n - 1 && x == m - 1) {
            return cur_time;
        }

        // 네 방향으로 탐색
        for (int i = 0; i < 4; ++i) {
            int newY = y + dy[i];
            int newX = x + dx[i];

            // 경계 검사
            if (newY >= 0 && newY < n && newX >= 0 && newX < m) {
                int new_time = cur_time + time_costs[newY][newX];
                int used_zeros = (maps[newY][newX] == 0) ? 1 : 0;

                // 0을 통과할 경우 통과 횟수를 늘림
                for (int k = 0; k <= max_zero_pass; ++k) {
                    if (k + used_zeros <= max_zero_pass && new_time < min_time[newY][newX][k + used_zeros]) {
                        min_time[newY][newX][k + used_zeros] = new_time;
                        pq.push({new_time, newY, newX});
                    }
                }
            }
        }
    }

    // 목적지에 도달할 수 없는 경우
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
    vector<vector<int>> time_costs = {
        {1, 2, 1, 1, 1},
        {1, 2, 1, 3, 1},
        {1, 1, 1, 4, 1},
        {3, 1, 5, 2, 1},
        {1, 1, 1, 1, 1}
    };
    int max_zero_pass = 2; // 최대 2번 0을 통과할 수 있는 조건
    cout << solution(map, time_costs, max_zero_pass) << endl;
}
