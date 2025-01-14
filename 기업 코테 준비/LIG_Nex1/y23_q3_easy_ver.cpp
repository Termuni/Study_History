// https://wondangcom.tistory.com/2310

/*
어떤 사람이 늑대 한마리, 염소 한마리, 양배추 한통을 가지고 강둑에 서 있다.
이 셋을 모두 배로 반대편으로 옮겨야 한다.
하지만 배에는 이 사람 외에는 하나만 실을 수 있다.
그 가 없으면 늑대는 염소를 먹어 버리고 염소는 양배추를 먹어 버린다.

늑대가 염소를 잡아먹지 못하고 또 염소가 양배추를 먹지 못하게 하면서 모두를 건너편 강가로 데려 갈 수 있을까?
그 경우 몇번 움직여야 할까?
*/


#include<iostream>
#include<stack>
#include<vector>

using namespace std;

//1. 염소를 옮긴다
//2. 돌아온다
//3. 늑대를 옮긴다
//4. 염소를 데리고 돌아온다
//5. 양배추를 옮긴다
//6. 돌아온다
//7. 염소를 옮긴다

enum {
    human, lamb, wolf, cabage    
};

vector<int> home, away;
int boat_weight = 0;

int movementCount(int lamb_count, int wolf_count, int cabage_count, int lamb_weight, int wolf_weight, int cabage_weight, int max_boat_weight)
{
    int answer = 0;
    
    if(((lamb_count == 0) && (wolf_count == 0)) && (cabage_count == 0))
    {
        return answer;
    }

    //1. 집에 셋 다 있는 경우

    //2. 집에 늑대와 양배추만 있는 경우

    //3. 건너편에 
}

int main()
{
    cout<<movementCount(1, 1, 1, 1, 1, 1, 1)<<endl;
}