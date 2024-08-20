/*
https://school.programmers.co.kr/learn/courses/30/lessons/42587

운영체제의 역할 중 하나는 컴퓨터 시스템의 자원을 효율적으로 관리하는 것입니다. 
이 문제에서는 운영체제가 다음 규칙에 따라 프로세스를 관리할 경우 특정 프로세스가 몇 번째로 실행되는지 알아내면 됩니다.

1. 실행 대기 큐(Queue)에서 대기중인 프로세스 하나를 꺼냅니다.
2. 큐에 대기중인 프로세스 중 우선순위가 더 높은 프로세스가 있다면 방금 꺼낸 프로세스를 다시 큐에 넣습니다.
3. 만약 그런 프로세스가 없다면 방금 꺼낸 프로세스를 실행합니다.
  3.1 한 번 실행한 프로세스는 다시 큐에 넣지 않고 그대로 종료됩니다.

예를 들어 프로세스 4개 [A, B, C, D]가 순서대로 실행 대기 큐에 들어있고, 
우선순위가 [2, 1, 3, 2]라면 [C, D, A, B] 순으로 실행하게 됩니다.

현재 실행 대기 큐(Queue)에 있는 프로세스의 중요도가 순서대로 담긴 배열 priorities와, 
몇 번째로 실행되는지 알고싶은 프로세스의 위치를 알려주는 location이 매개변수로 주어질 때, 
해당 프로세스가 몇 번째로 실행되는지 return 하도록 solution 함수를 작성해주세요.
*/
/*
만약 queue에서 max를 찾는 함수를 알고있다면, 앞의 큐를 뽑아서 맨 뒤로 보내는 방식으로 한방에 찾는 방식이 있음
*max_element(begin, end)를 통해 가능
*/
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    //받은 것 front~end 확인, 프로세스 우선순위 1~9 개수 확인
    //각 우선순위에 대해 해당 우선 순위의 개수만큼 searching, 반납
    //필요 자료형 : int array [10] -> 1~9 갯수 저장
    //필요 정보 : int nowIdx(priorities의 시작부터 끝까지 현재 어느 Idx인지 확인하기 위함)
    //제일 프로세스 큰 숫자가 뭐인지 확인하는 processMax
    //while processMax != 0 -> processMax는 9~1까지 내려올 예정
    //nowIdx에서 제일 
    int answer = 0;
    vector<int> temp;
    vector<int> sorted = priorities;
    sort(sorted.begin(), sorted.end(), greater<>());
    while(temp.size() < priorities.size()){
        //정리된거 처음부터 하나씩 앞에서부터 찾아서 넣어주기
    }
    return answer;
}
