#include <string>
#include <iostream>
#include <vector>

using namespace std;


void BFS(vector<int> * number, int idx, int sum, int target, int * count, bool oper)
{
    sum = (oper)? sum+(*number)[idx++] : sum-(*number)[idx++];
    //++idx;

    if((idx == (*number).size()))
    {
        if(target == sum)
        {
            *count = *count+1;
        }
    }
    else
    {
        BFS(number, idx, sum, target, count, true);
        BFS(number, idx, sum, target, count, false);
    }
}


int solution(vector<int> numbers, int target) {
    int answer = 0;
    //glob_nums = numbers;
    BFS(&numbers, 0, 0, target, &answer, true);
    BFS(&numbers, 0, 0, target, &answer, false);
    return answer;
}


int main()
{
    cout<<solution({1,1,1,1,1},3)<<endl;
    cout<<solution({1,2,1,3,2},3)<<endl;
    cout<<solution({1,5,2,8,7},3)<<endl;
    cout<<solution({4,1,2,1},4)<<endl;
}