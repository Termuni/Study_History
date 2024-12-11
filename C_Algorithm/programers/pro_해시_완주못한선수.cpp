//https://school.programmers.co.kr/learn/courses/30/lessons/42576
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

string solution(vector<string> participants, vector<string> completions) {
    string answer = "";
    unordered_map<string,int> map;
    for(auto participant : participants)
    {
        if(map.find(participant) == map.end())
        {
            map.insert(make_pair(participant, 1));
        }
        else
        {
            ++map[participant];
        }
    }
    for(auto completion : completions)
    {
        --map[completion];
    }
    for(auto participant : participants)
    {
        if(map[participant] != 0)
        {
            answer = participant;
            break;
        }
    }
    return answer;
}

int main()
{
    cout<<solution({"leo", "kiki", "eden"}, {"eden", "kiki"})<<endl;
    return 0;
}
