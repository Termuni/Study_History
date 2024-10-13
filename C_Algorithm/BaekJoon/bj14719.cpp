//https://www.acmicpc.net/problem/14719

/*
예제 입력
4 8
3 1 2 3 4 1 1 2

첫 번째 줄에는 2차원 세계의 세로 길이 H과 2차원 세계의 가로 길이 W가 주어진다. (1 ≤ H, W ≤ 500)
두 번째 줄에는 블록이 쌓인 높이를 의미하는 0이상 H이하의 정수가 2차원 세계의 맨 왼쪽 위치부터 차례대로 W개 주어진다.
따라서 블록 내부의 빈 공간이 생길 수 없다. 또 2차원 세계의 바닥은 항상 막혀있다고 가정하여도 좋다.
2차원 세계에서는 한 칸의 용량은 1이다. 고이는 빗물의 총량을 출력하여라.
빗물이 전혀 고이지 않을 경우 0을 출력하여라.
*/

/*
풀이 고민
1. 세로로 돌려서 생각, 첫 시작 위치에서 비어있는 곳 부터 다음 그 값 나올때까지 제거
즉
XXXOXXXXXX
OXXOXXXOXX
OXOOXOXOXO
OOOOOOOOOO
와 같이 되어있는 경우, 세로로 돌려서
OOOX
OXXX
OOXX
OOOO
OXXX
OOXX
OXXX
OOOX
OXXX
OOXX
와 같이 돌림
2-1. 시작 위치의 맨 끝 확인, X면 그 이후 O 나오기 전까지 X처리(제거), 만약 안 나오면 flag = false 전달
2-2. 그 다음 확인, flag = False면 X면 동일하게 다 지우고, O면 다음 O 나올 때까지 더해주기
2-3. 만약 다음 O가 안 나오면 쭉 제거 한 뒤, 그 다음 아래 X 검사

이 과정을 원래 받은 대로 구현하는게 나을 것 같은데
어떻게 할까?

1. 시작하는 장소(a0)의 높이를 기준으로, 그 높이보다 높은 곳이 있는지 검색
2. 그 높이 기준으로 다음 높은 곳(a1) 까지 위치를 저장
3. 그 사이를 모두 제거, 즉 계산 안 함
4. 그 다음 높이로 계산
5. 

*/
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int T;
    int N, M, K;
    int X, Y;
    int answer = 0;

    cin >> N >> M;
    vector<int> v(M);   //  v 벡터를 M개 크기만큼 할당

    for (int i = 0; i < M; i++)
        cin >> v[i];

    for (int i = 1; i < M - 1; i++) {
        int left = 0; int right = 0;
        //왼쪽 최대 값
        for (int j = 0; j < i; j++) left = max(left, v[j]);
        //오른쪽 최대 값
        for (int j = M - 1; j > i; j--) right = max(right, v[j]);
        //빗물 계산
        answer += max(0, min(left, right) - v[i]);
    }

    cout << answer << endl;
    return 0;
}