/*
단지번호붙이기

<그림 1>과 같이 정사각형 모양의 지도가 있다.
1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다.

철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다.
여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다.
대각선상에 집이 있는 경우는 연결된 것이 아니다.

<그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다.
지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고,
그 다음 N줄에는 각각 N개의 자료(0 혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오.
그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

예제 입력
7
0110100
0110101
1110101
0000111
0100000
0111110
0111000

예제 출력
3
7
8
9

*/

/*
이 문제에서
0110100         0110200
0110101         0110202
1110101         1110202
0000111         0000222
0100000         0300000
0111110         0333330
0111000         0333000

로, 변화 된다고 한다

IDEA
2차원 배열을 2개 생성한다
1개는 int, 1개는 bool

왼쪽 상단에서 시작하여, 그 자리가 1이고 false라면 그 자리부터 우/하/좌/상 검색
해당 자리에서 인근 자리 검색했을 때 만약 있으면? 그 자리에서 다시 우/하/좌/상 검색

시간복잡도 아마 n^4? 정도 아닐까?
계산 해보면 약 39만 계산으로 나온다

그렇다면 어떻게 갯수를 카운팅하지?

함수를 만들고, 포인터로 현재 숫자를 넘겨서 가능한 경우마다 더해주기
그리고 아파트 갯수에 넣어주기
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;

//Number of Aparts Counter
vector<int> apart;

//is that apart visited?
vector<vector<bool> > visited;

// Direction,Down/Up/Right/Left
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void Count(int * count, int x, int y)
{
    //내 위치의 visited가 false면 return
    if(!visited[y][x]) return;

    //true면 카운트 추가하고 false로 만들어주기(다신 방문 안 하게)
    *count += 1;
    visited[y][x] = false;

    //상/하/좌/우 탐색
    for(int i=0; i<4; ++i)
    {
        if (x + dx[i] >= 0 && x + dx[i] < n && y + dy[i] >= 0 && y + dy[i] < n)
        {
            int newX = x + dx[i], newY = y + dy[i];
            if(visited[newY][newX])
            {
                Count(count, newX, newY);
            }
        }
    }
}

int main()
{
    cin >> n;

    // Save Data of 2x2 Apart, pair is [isThereApart] and position of vector
    visited.resize(n, vector<bool>(n, false));

    for (int i = 0; i < n; ++i)
    {
            //bool로 0110100 들어오면 이걸 그냥 true로 받아버리기에
            //string으로 받은 뒤 char 단위로 쪼갤 예정
            string isThereApart;
            cin >> isThereApart;
            for(int j = 0; j < n; ++j)
            {
                //3항 연산자로, char == '1' 인 경우만 true 넣어주기
                visited[j][i] = (isThereApart[j] == '1')? true : false;
            }
    }
    
    //생각 할 수록 깊이 탐색이 맞음!
    //count, posY, posX 등 넘겨서 진행하기
    for(int y = 0; y < n; ++y)
    {
        for(int x = 0; x < n; ++x)
        {
            int count = 0;
            Count(&count, x, y);
            if(count != 0)
            {
                apart.push_back(count);
            }
        }
    }
    
    //오름차순 정렬
    sort(apart.begin(), apart.end());

    cout<<apart.size()<<'\n';
    for(int i = 0; i < apart.size(); ++i)
    {
        cout<<apart[i]<<'\n';
    }
}
