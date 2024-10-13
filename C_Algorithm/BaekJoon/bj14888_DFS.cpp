//연산자 끼워넣기
//https://www.acmicpc.net/problem/14888

// 1 2 3 4 5 6
// 숫자 개수 : n개
// 연산자 개수 : n-1개
// 숫자 크기 : 1~100
// 최대 가짓수 : n-1 P n-1?
// 5 6 / 0 0 1 0  -> 1P0
// 5 6 7 / 1 0 1 0 -> 2 P 

//최대 가짓수 : 92400가지 (11! / (3! * 3! * 3!*/ 2!) )
#define MAXVALUE (2100000000)
#define MINVALUE (-2100000000)
#define MAXCOMBINATION 92401
#include<iostream>
#include<vector>


using namespace std;

vector<int> numbers;

vector<int> values;

int operators[4];

int n;

void DFS(int step, int value, int tar_Op) {
    if(operators[tar_Op] == 0){
        return;
    }
    switch (tar_Op)
    {
    case 0:
        value += values[step-1];
        break;
    case 1:
        value -= values[step-1];
        break;
    case 2:
        value = value * values[step-1];
        break;
    case 3:
        value = value/values[step-1];
        break;
    }
    if(step == n-1){
        values.push_back(value);
    }
    else{
        for(int i=0; i<4; ++i){
            DFS(step+1, value, i);
        }
    }
}

int main()
{
    //open
    //freopen("input_INSERT.txt","rt",stdin);

    //숫자 몇개 들어올 것인지
    cin>>n;

    //숫자 입력받기
    for(int i=0; i<n; ++i){
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    //연산자 입력받기
    for(int i=0; i<4; ++i){
        int input;
        cin>>input;
        operators[i] = input;
    }

    //전체 탐색
    for(int i=0; i<4; ++i){
        DFS(1, values[0], i);
    }

    for(int i=0; i<values.size(); ++i){
        cout<<values[i]<<'\n';
    }
}
