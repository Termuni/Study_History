//연산자 끼워넣기
//https://www.acmicpc.net/problem/14888
#define MAX -2000000000  //-20억
#define MIN 2000000000  //20억
#include<iostream>
#include<math.h>

using namespace std;

int n;
int maxi = MAX, mini = MIN;
int numbers[11];
int operators[4];

void solution(int idx, int result){
    if(idx == n){
        if(result > maxi){
            maxi = result;
        }
        if(result < mini){
            mini = result;
        }
        return;
    }
    for(int i = 0; i < 4; ++i){
        if(operators[i] > 0){
            operators[i]--;
            switch (i)
            {
            case 0:
                solution(idx + 1, result + numbers[idx]);
                break;
            case 1:
                solution(idx + 1, result - numbers[idx]);
                break;
            case 2:
                solution(idx + 1, result * numbers[idx]);
                break;
            case 3:
                solution(idx + 1, result / numbers[idx]);
                break;
            }
            operators[i]++;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> numbers[i];
    }
    for(int i = 0; i < 4; ++i){
        cin >> operators[i];
    }
    solution(1, numbers[0]);
    cout<< maxi << ' ' << mini << endl;
}
