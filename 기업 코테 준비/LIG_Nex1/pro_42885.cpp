//https://school.programmers.co.kr/learn/courses/30/lessons/42885
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int kg[241];
int max_kg = 40;
int min_kg = 240;

int solution(vector<int> people, int limit) {
    bool isDone = false;
    int answer = 0;
    //Set kg[241] to 0
    for(int i=0; i<=240; ++i)
    {
        kg[i] = 0;
    }
    //Set each kg Adding
    for(int i=0; i<people.size(); ++i)
    {
        max_kg = max(max_kg, people[i]);
        min_kg = min(min_kg, people[i]);
        kg[people[i]] += 1;
    }
    while(!isDone)
    {
        int num = 0;
        //max_kg 갱신
        while(kg[max_kg] == 0)
        {
            --max_kg;
        }
        //min_kg 갱신
        while(kg[min_kg] == 0)
        {
            ++min_kg;
        }
        int left_kg = limit;
        int target_kg = max_kg;
        
        //무게 빼기
        while((left_kg >= min_kg) &&(num != 2))
        {
            if((kg[target_kg] > 0) && ((left_kg - target_kg) >= 0))
            {
                ++num;
                left_kg -= target_kg;
                --kg[target_kg];
                continue;
            }
            --target_kg;
        }
        
        ++answer;
        
        //반복 끝나는 조건 설정
        if((max_kg == min_kg)&&((kg[min_kg] == 0)&&(kg[max_kg] == 0)))
        {
            isDone = true;
        }
    }
    return answer;
}