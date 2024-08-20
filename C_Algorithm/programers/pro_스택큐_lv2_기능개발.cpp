/*
https://school.programmers.co.kr/learn/courses/30/lessons/42586
프로그래머스 팀에서는 기능 개선 작업을 수행 중입니다. 
각 기능은 진도가 100%일 때 서비스에 반영할 수 있습니다.

또, 각 기능의 개발속도는 모두 다르기 때문에 
뒤에 있는 기능이 앞에 있는 기능보다 먼저 개발될 수 있고, 
이때 뒤에 있는 기능은 앞에 있는 기능이 배포될 때 함께 배포됩니다.

먼저 배포되어야 하는 순서대로 작업의 진도가 적힌 정수 배열 progresses와 
각 작업의 개발 속도가 적힌 정수 배열 speeds가 주어질 때 
각 배포마다 몇 개의 기능이 배포되는지를 return 하도록 solution 함수를 완성하세요.
*/
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    //progress[1]과 speed[1]을 통해 몇일 걸리는지 계산해서 새로운 queue에 저장
    //queue의 앞부터 확인, temp에 담고 그 temp와 다음의 queue값을 비교
    //만약 다음의 queue가 temp보다 작으면 한번에 배포할 개수+1
    //만약 다음의 queue가 temp보다 크면 answer에 push_back
    queue<int> days;
    for(int i = 0; i < progresses.size(); ++i){
        int day = (100 - progresses[i]) / speeds[i];
        if((100-progresses[i]) % speeds[i] != 0){
            day += 1;
        }
        days.push(day);
        cout<< day <<' ';
    }
    cout<<endl;

    int temp = days.front();
    int result = 1;
    days.pop();
    while(days.size() > 0){
        if(days.front() > temp){
            temp = days.front();
            answer.push_back(result);
            days.pop();
            result = 1;
        }
        else{
            result++;
            days.pop();
        }
    }
    answer.push_back(result);
    return answer;
}