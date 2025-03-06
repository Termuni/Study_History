/*
n가지 종류 동전, 각 동전이 나타내는 가치는 다름
이 동전을 적당히 사용, 가치 합 k원 되는 경우의 수
사용 동전 구성이 같은데 순서만 다른 것 -> 같은 경우

입력
n k (1 <= n <= 100, 1 <= k <= 10000)
n1
n2
...
nn
*/

/*
예제 입력
3 10
1
2
5

이 경우 10을 만드는 경우의 수
1 1 1 ... 1 1   -> 1 10개
1 1 1 ... 1 2   -> 1 8개, 2 1개
1 1 1 ... 2 2   -> 1 6개, 2 2개
1 1 1 1 1 5     -> 1 5개, 2 0개, 5 1개
1 1 1 1 2 2 2   -> 1 4개, 2 3개, 5 0개
1 1 1 2 5       -> 1 3개, 2 1개, 5 1개
1 1 2 2 2 2     -> 1 2개, 2 4개, 5 0개
1 2 2 5         -> 1 1개, 2 2개, 5 1개
2 2 2 2 2       -> 1 0개, 2 5개, 5 0개
5 5             -> 1 0개, 2 0개, 5 2개

출력
10


6 20
2
3
4
5
6
7

2*0 + 3*0 + 4*0 + 5*0 + 6*0 + 7*0 = 0
2*1 + 3*0 + 4*0 + 5*0 + 6*0 + 7*0 = 2
2*2 + 3*0 + 4*0 + 5*0 + 6*0 + 7*0 = 4
2*3 + 3*0 + 4*0 + 5*0 + 6*0 + 7*0 = 6
...
2*10 + 3*0 + 4*0 + 5*0 + 6*0 + 7*0 = 20 -> Count++
2*11 + 3*0 + 4*0 + 5*0 + 6*0 + 7*0 = 22 => Over, Next
2*0 + 3*1 + 4*0 + 5*0 + 6*0 + 7*0 = 3
2*1 + 3*1 + 4*0 + 5*0 + 6*0 + 7*0 = 5
...
2*9 + 3*1 + 4*0 + 5*0 + 6*0 + 7*0 = 21 => Over, Next
2*0 + 3*2 + 4*0 + 5*0 + 6*0 + 7*0 = 6
...
2*7 + 3*2 + 4*0 + 5*0 + 6*0 + 7*0 = 20 -> Count++
2*8 + 3*2 + 4*0 + 5*0 + 6*0 + 7*0 = 22 => Over, Next
...
2*0 + 3*2 + 4*0 + 5*0 + 6*0 + 7*2 = 20 -> Count++
...
2*0 + 3*7 + 4*0 + 5*0 + 6*0 + 7*0 = 21 => Over, Next
2*0 + 3*0 + 4*1 + 5*0 + 6*0 + 7*0 = 4
...
2*1 + 3*5 + 4*1 + 5*0 + 6*0 + 7*0 = 21 => Over, Next
2*0 + 3*6 + 4*1 + 5*0 + 6*0 + 7*0 = 22 => Over, Next
2*0 + 3*0 + 4*2 + 5*0 + 6*0 + 7*0 = 8
...
2*0 + 3*0 + 4*0 + 5*0 + 6*0 + 7*3 = 21 => Over, END

이렇게 해서, (최종 목표 숫자 / 제일 큰 숫자) + 1 만큼 온 경우 끝내기

-> 약 50분 걸려서 도출해낸 방법

다른 사람 풀이
https://yabmoons.tistory.com/491


*/
/*
#include<iostream>

using namespace std;

int nums[101], counts[101], num, target;

int main()
{
    //INIT
    int sum = 0, answer = 0;
    for(int i=0; i<=100; ++i)
    {
        nums[i] = 0;
        counts[i] = 0;
    }

    //Input
    cin>>num>>target;
    for(int i=0; i<num; ++i)
    {
        int temp;
        cin>>temp;
        nums[i] = temp;
    }
    
    //최대 counts의 값이 0이면 지속, 아니면 취소
    while(counts[num]==0)
    {
        sum = 0;
        //조건 따지기 위해 Sum 값을 계산
        for(int i=0; i<num; ++i)
        {
            sum += nums[i] * counts[i];            
        }

        // cout<<"Sum : "<<sum<<'\n';

        //아직 더 더해야 하는 경우
        if(sum < target)
        {
            counts[0] += 1;
        }//아직 더 더해야 하는 경우

        //그만 더해도 되는 경우
        else
        {
            answer = (sum==target) ? answer+1 : answer;
            int checker = 0;
            while(true)
            {
                if(counts[checker] != 0)    //만약 그 카운트 값이 0이 아닌 경우
                {
                    counts[checker+1] += 1;
                    counts[checker] = 0;
                    break;
                }
                else
                {
                    checker += 1;
                }
            }
        }//그만 더해도 되는지 판단

    }//전체 While

    cout<<answer<<endl;
}
*/

#include<iostream>

using namespace std;

int nums[100010];
int n, k;

int main()
{
    //INIT
    nums[0] = 1;
    for(int i=1; i<100010; ++i)
    {
        nums[i] = 0;
    }

    //INPUT
    cin >> n >> k;

    for(int i=0; i<n; ++i)
    {
        int coin;
        cin>>coin;
        nums[coin] += 1;
        for(int j = coin + 1; j <= k; ++j)
        {
            nums[j] = nums[j] + nums[j-coin];
        }
    }

    
    for(int i=0; i<=k; ++i)
    {
        cout << i << "th : " << nums[i] << endl;
    }

    return 0;
}