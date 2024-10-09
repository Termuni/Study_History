// vector<int>[i]의 각 요소에 대하여
// [i]%5 == 0이면 	Out
// [i]%5 == 1이면 	모든 주자 +1루 진루
// [i]%5 == 2이면 	모든 주자 +2루 진루
// [i]%5 == 3이면 	모든 주자 +3루 진루
// [i]%5 == 4이면 	모든 주자+타자 홈인
// Out == 3이면 이후 결과와는 상관 없이 end
// input을 받아 위에 따른 score를 계산하시오 	
// input 예시 	output 예시
// {4, 61, 70, 0, 12, 65}	1
// {0,0,0,4,4,4}	0
// {1,1,1,4,0,0,4}	5

#include<iostream>
#include<vector>

using namespace std;

int calculateScore(const vector<int>& v)
{
    for(int i=0; i<v.size(); ++i)
    {
        cout<<v[i]<< ' ';
    }cout<<endl;
    int score = 0, out_count = 0, round = 0;
    bool base[4] = {false, false, false, false};
    while(out_count != 3)
    {
        switch (v[round]%5)
        {
        case 0:
            ++out_count;
            cout<<"OUT!!"<<'\n';
            break;
        case 1:
            score = (base[3])?(score+1):score;
            base[3] = (base[2])?true:false;
            base[2] = (base[1])?true:false;
            base[1] = true;
            break;
        case 2:
            score = (base[3])?(score+1):score;
            score = (base[2])?(score+1):score;
            base[3] = (base[1])?true:false;
            base[2] = true;
            base[1] = false;
            break;
        case 3:
            score = (base[3])?(score+1):score;
            score = (base[2])?(score+1):score;
            score = (base[1])?(score+1):score;
            base[3] = true;
            base[2] = false;
            base[1] = false;
            break;
        case 4:
            score = (base[3])?(score+1):score;
            score = (base[2])?(score+1):score;
            score = (base[1])?(score+1):score;
            ++score;
            base[3] = false;
            base[2] = false;
            base[1] = false;
            break;
        }
        ++round;
    }
    return score;
}

int main() {
    vector<int> test = {4, 61, 70, 0, 12, 65};
    cout << calculateScore(test) << endl; // 1
    test = {0,0,0,4,4,4};
    cout << calculateScore({0,0,0,4,4,4}) << endl; // 0
    test = {1,1,1,4,0,0,4};
    cout << calculateScore({1,1,1,4,0,0,4}) << endl; // 5
    return 0;
}

/*
// BOJ 1~3주차 복습 ctrl_alt_c + ctrl_alt_r
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int calculateScore(const vector<int>& v) {
    int score = 0;
    int out = 0;
    // bases[0]: 1루, [1]: 2루, [2]: 3루
    vector<bool> bases(3, false); // 1루, 2루, 3루의 주자 유무를 나타냄
    for (int action : v) {
        if (out == 3) {
            return 0; // out 값이 3이면 점수를 계산하지 않고 0 반환
        }
        int mod = action % 5;
        if (mod == 0) {                 // 1. 나머지 = 0이면, out++
            out++;
        } else if (mod == 4) {          // 2. 나머지 = 4이면, 홈런 -> score 1 증가
            score += 1; // 타자 점수
            for (bool base : bases) {   // 2.1 주자 있으면 모두 score 1 증가 후, bases 초기화
                if (base) score++;
            }
            fill(bases.begin(), bases.end(), false);
        } else {                        // 3. 1,2,3루 기존 타자 진루 및 현재 타자 진루
            for (int i = 2; i >= 0; i--) {
                if (bases[i]) {
                    if (i + mod >= 3) { // -> 인덱스로 봐라. 0~2가 1~3루니까, 3이면 홈이면서 score++
                        score++; // 홈으로 들어옴
                        bases[i] = false; // 진루하게 될 곳이 홈 이상이니까 score 증가하고, 기존 자리 false로 비워
                    } else {
                        bases[i + mod] = true; // 기존에 사람 없었으면, 움직이게 될 곳으로 진루
                        bases[i] = false; // 기존 있던 자리 초기화
                    }
                }
            }
            if (mod < 4) { // 배열은 음수 못오니까 1,2,3루만 해당. 해당 위치로 진루
                bases[mod - 1] = true; // 타자 진루
            }
        }
    }
    return score;
}
int main() {
    cout << calculateScore({4, 61, 70, 0, 12, 65}) << endl; // 1
    cout << calculateScore({0,0,0,4,4,4}) << endl; // 0
    cout << calculateScore({1,1,1,4,0,0,4}) << endl; // 5
    return 0;
}
*/