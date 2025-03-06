/*
BaekJoon 2293 -> 동전 1
동전 2

[입력]
n가지 종류 동전, 가치 합 k원 되도록 할 예정 (1 <= n <= 100, 1<= k <= 10,000)
동전 개수 최소화
동전은 몇 개든 사용 가능
가치가 같은 동전이 여러번 주어질 수 있음

[출력]
첫째줄에 사용한 동전의 최소 개수 출력, 불가능 한 경우 -1

입력
n k  
n1
n2
n3
...
nn

예제 입력
3 15
1
5
12

예제 출력
3

*/

/*

문제의 포인트 
1. 같은 가치의 동전 입력 가능 -> 중복은 제거 필요
2. 최소 개수가 되는 방법 찾아서, 동전 개수 저장

IDEA
1. k값보다 큰 값은 저장 x
2. 점화식 필요할 것 같음 -> 1원을 만드는 방법부터 해서, 1만원을 만드는 방법까지, 최소한으로...
3. 1원부터 1만원까지, 각 숫자로 나눈 값을 비교해서 더 작은 값을 넣는다?

예를들어, 
3 15
2
5
12

제일 작은 숫자인 2로 시작
for문의 i, j
dp[0] = 0
i=1 -> input_step = 1
j=1 dp[1] = -1
dp[2] = if(i==n[j]) dp[i] = 1
dp[3] = if(dp[1] != -1) dp[2] + dp[1] / else -1
dp[4] = if(dp[i-j] != -1) dp[j] + dp[i-j] / else -1
...
dp[15] = if(dp[15-2] != -1) dp[j] + dp[i-j]



*/

#define MAX_DATA_NUM 10010
#include <iostream>

using namespace std;

int used_coins[MAX_DATA_NUM];

int n, k;

int main()
{
    //INIT
    //used_coins[0] = -1;
    for(int i=0; i<MAX_DATA_NUM; ++i)
    {
        used_coins[i] = -1;
    }

    //INPUT
    cin >> n >> k;
    for(int input_step = 1; input_step <= n; ++input_step)
    {
        int input_number;
        cin >> input_number;
        for(int count_number = input_number; count_number<=k; ++count_number)
        {
            //만약 입력 값이 count_number와 정확히 같은 값이라면, 그 값은 무조건 1
            if(input_number == count_number)
            {
                used_coins[count_number] = 1;
            }
            //만약 count_number값에서 현재 input_number를 뺀 값이 -1이 아니라면, -> if(used_coins[count_number - input_number] != -1)
            //used_coins[count_number]에 들어갈 값은 used_coins[count_number - input_number] + 1 -> 만약 그 값이 더 작은 경우만!
            else if(used_coins[count_number - input_number] != -1)
            {
                if(used_coins[count_number] == -1)
                {
                    used_coins[count_number] = used_coins[count_number - input_number] + 1;
                }
                else
                {
                    used_coins[count_number] = (used_coins[count_number] < used_coins[count_number - input_number] + 1) ? 
                        used_coins[count_number] : used_coins[count_number - input_number] + 1;
                }
            }
        }
    }
    // for(int i=0; i<=k; ++i)
    // {
    //     cout<< i << "th : " << used_coins[i] << '\n';
    // }
   cout<<used_coins[k];

}