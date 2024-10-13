// https://school.programmers.co.kr/learn/courses/30/lessons/1844

//내 풀이는 DFS였고, 이는 효율적인 방법이 아니며 오류도 있음
/*
#include<iostream>


#include<algorithm>
#include<vector>
using namespace std;

vector<int> move_count;
//input : [[1,0,1,1,1],
//         [1,0,1,0,1],
//         [1,0,1,1,1],
//         [1,1,1,0,1],
//         [0,0,0,0,1]]	
//output : 11

bool check_Enemy(vector<vector<int> > * maps, int enemy_y, int enemy_x)
{
    if(((*maps)[enemy_y-1][enemy_x] == 0) && ((*maps)[enemy_y][enemy_x-1] == 0))
    {
        return false;
    }
    return true;
}

void move(vector<vector<int> > * maps, vector<vector<bool>> visited, int direction, int count, int now_y, int now_x ,int * enemy_y, int * enemy_x)
{
    if(now_y == *enemy_y && now_x == *enemy_x)
    {
        count += 1;
        move_count.push_back(count);
        return;
    }
    switch(direction)
    {
        //up
        case 1:
            if(now_y - 1 < 0) break;
            if((*maps)[now_y-1][now_x] == 0) break;
            if(visited[now_y-1][now_x]) break;
            visited[now_y][now_x] = true;
            now_y-=1;
            move(maps, visited,  1, count+1, now_y, now_x, enemy_y, enemy_x);
            move(maps, visited, 3, count+1, now_y, now_x, enemy_y, enemy_x);
            move(maps, visited, 4, count+1, now_y, now_x, enemy_y, enemy_x);
            break;
        //down
        case 2:
            if(now_y + 1 > *enemy_y) break;
            if((*maps)[now_y+1][now_x] == 0) break;
            if(visited[now_y+1][now_x]) break;
            visited[now_y][now_x] = true;
            now_y+=1;
            move(maps, visited, 2, count+1, now_y, now_x, enemy_y, enemy_x);
            move(maps, visited, 3, count+1, now_y, now_x, enemy_y, enemy_x);
            move(maps, visited, 4, count+1, now_y, now_x, enemy_y, enemy_x);
            break;
        //left
        case 3:
            if(now_x - 1 < 0) break;
            if((*maps)[now_y][now_x-1] == 0) break;
            if(visited[now_y][now_x-1]) break;
            visited[now_y][now_x] = true;
            now_x-=1;
            move(maps, visited, 1, count+1, now_y, now_x, enemy_y, enemy_x);
            move(maps, visited, 2, count+1, now_y, now_x, enemy_y, enemy_x);
            move(maps, visited, 3, count+1, now_y, now_x, enemy_y, enemy_x);
            break;
        //right
        case 4:
            if(now_x + 1 > *enemy_x) break;
            if((*maps)[now_y][now_x+1] == 0) break;
            if(visited[now_y][now_x+1]) break;
            visited[now_y][now_x] = true;
            now_x+=1;
            move(maps, visited, 1, count+1, now_y, now_x, enemy_y, enemy_x);
            move(maps, visited, 2, count+1, now_y, now_x, enemy_y, enemy_x);
            move(maps, visited, 4, count+1, now_y, now_x, enemy_y, enemy_x);
            break;
    }
}

int solution(vector<vector<int> > maps)
{
    //maps[0] -> y축
    //maps[0][0] -> 1,1
    int answer = 2e+9;
    int enemy_y = maps.size()-1, enemy_x = maps[0].size()-1;
    int count = 0;
    bool available = check_Enemy(&maps, enemy_y, enemy_x);
    vector<vector<bool>> visited;
    for(int i=0; i<=enemy_y; ++i)
    {
        vector<bool> temp;
        for(int j=0;j<=enemy_x; ++j)
        {
            temp.push_back(false);
        }
        visited.push_back(temp);
    }
    if(available)
    {
        //down
        move(&maps, visited, 2, 0, 0, 0, &enemy_y, &enemy_x);
        //right
        move(&maps, visited, 4, 0, 0, 0, &enemy_y, &enemy_x);
    }
    else
    {
        answer = -1;
    }
    for(int i=0; i<move_count.size(); ++i)
    {
        answer = min(answer, move_count[i]);
    }
    return answer;
}

int main()
{
    cout<<solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}})<<'\n';
    cout<<solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,0,1},{1,1,1,0,1},{0,0,0,0,1}})<<'\n';
    cout<<solution({{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}})<<'\n';
}
*/
//GPT 풀이는 BFS였고, 이는 효율적인 방법이며 오류도 없음
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[] = {-1, 1, 0, 0}; // 상, 하
int dx[] = {0, 0, -1, 1}; // 좌, 우

int solution(vector<vector<int>> maps) {
    int n = maps.size();       // y축 크기
    int m = maps[0].size();    // x축 크기
    
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q; // ((y,x), 이동 거리)
    
    q.push({{0, 0}, 1});  // 시작점 (0,0)에서 시작, 거리 1
    visited[0][0] = true; // 시작점 방문 처리
    
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dist = q.front().second;
        q.pop();
        
        // 목적지 도착하면 거리 반환
        if (y == n-1 && x == m-1) return dist;
        
        // 상하좌우 탐색
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            // 유효 범위 안에 있는지 확인하고, 벽이 아닌지, 방문한 적 없는지 체크
            if (ny >= 0 && ny < n && nx >= 0 && nx < m && maps[ny][nx] == 1 && !visited[ny][nx]) {
                visited[ny][nx] = true; // 방문 처리
                q.push({{ny, nx}, dist + 1}); // 거리 1 증가시켜 큐에 추가
            }
        }
    }
    
    // 큐가 비었는데도 도착하지 못했으면 경로가 없는 경우
    return -1;
}

int main() {
    vector<vector<int>> maps1 = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,1},{0,0,0,0,1}};
    vector<vector<int>> maps2 = {{1,0,1,1,1},{1,0,1,0,1},{1,0,1,1,1},{1,1,1,0,0},{0,0,0,0,1}};
    
    cout << solution(maps1) << endl; // Expected output: 11
    cout << solution(maps2) << endl; // Expected output: -1
    
    return 0;
}
