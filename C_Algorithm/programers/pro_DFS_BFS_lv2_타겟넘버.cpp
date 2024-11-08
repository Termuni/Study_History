#include <string>
#include <iostream>
#include <vector>

using namespace std;


void BFS(vector<int> * numbers, int idx, int sum, int target, int * count, bool oper)
{
    //if adder

    if(oper)
    {
        sum += (*numbers)[idx];
    }
    else
    {
        sum -= (*numbers)[idx];
    }
    ++idx;
    if(idx == (*numbers).size())
    {
        if(target == sum)
        {
            *count = *count+1;
        }
    }
    else
    {
        BFS(numbers, idx, sum, target, count, true);
        BFS(numbers, idx, sum, target, count, false);
    }
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    BFS(&numbers, 0, 0, target, &answer, true);
    BFS(&numbers, 0, 0, target, &answer, false);
    return answer;
}