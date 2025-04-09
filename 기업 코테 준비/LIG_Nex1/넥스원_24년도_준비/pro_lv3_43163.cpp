// https://school.programmers.co.kr/learn/courses/30/lessons/43163

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//시작 단어 받고, words 맨 앞에서부터 한 개만 다른 단어 있는지 탐색
//단어 별 맨 앞 부터 빠르게 바꿀 수 있는 친구 있는지 탐색
//만약 없으면 다음 중간 단어만 빠르게 바꿀 수 있는지 탐색
//그렇게 바꿔서 queue로 탐색?

bool wordChangable(string target1, string target2)
{
    int count = 0;
    for(int i=0; i<target1.length(); ++i)
    {
        if(target1[i] != target2[i])
        {
            count+=1;
            if(count > 1) return false;
        }
    }
    return (count==1)?true:false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string, int> > check; check.push(make_pair(begin, 0));
    vector<bool> visited(words.size(), false);
    while(check.size() > 0)
    {
        string word = check.front().first;
        int count = check.front().second;
        check.pop();
        
        if(word == target) return count;

        for(int i=0; i<words.size(); ++i)
        {
            if(wordChangable(word, words[i]) && !visited[i])
            {
                check.push(make_pair(words[i], count+1));
                visited[i]=true;
            }
        }
    }
    return answer;
}

int main()
{
    cout<<solution("hit","cog",{"hot", "dot", "dog", "lot", "log", "cog"})<<endl;
}