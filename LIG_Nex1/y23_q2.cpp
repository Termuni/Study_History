// input 예시 	    input 2 예시	output 예시
//1. {3,7,8}, 	    2	            8
//2. {3,4,8}, 	    1	            4
//3. {1,2,3,4,5,6} 	2	            2
//4. [3,4,7,8]	    1	            2

// 설명		
// vector<int>[i]의 각 요소에 대하여		
// 각 [i]초에서 interrupt가 발생한다.		
// interrupt를 검사하는 주기를 최대로 하는 것을 목표로 최대 검사주기를 구한다.		
// 조건 1: 모든 인터럽트는 검사되어야 하며		
// 조건 2: 한 주기에서는 인터럽트를 (input 2)개를 초과하여 검사할 수 없다.		
// 예시 : [0 1 2 3 4 5 6 7] / [8] 나눴을떄	input 2 = 2	최대 검사주기 = 8
// 예시 : [0 1 2 3] / [4 5 6 7] / [8] 로 나눴을떄	input 2 = 1	최대 검사주기 = 4
// 예시 : [0,1]/[2,3]/[4,5], [6,7]/[8] 로 나눴을떄	input 2 = 1	최대 검사주기 = 2

/* 
//문제에 안 적혀있긴 한데, 최대 시간은 그냥 마지막 숫자인 듯?
//input 1 -> 인터럽트의 위치
//아마 input2 -> 한 번의 최대 인터럽트 개수
//1번의 경우 0~7까지 3, 7 두번 인지 가능 -> 최대가 8이 가능
//2번의 경우 0~3까지 3 한 번, 4~7까지 4 한번, 8 한번 인지 가능 -> 최대 4 가능
//3번의 경우 1, 2, 3, 4, 5, 6 각각 있으나 2개 인지 가능 -> 최대 2 가능
//4번의 경우 0~3 가능하나, 4~7에서 두번 걸려서 불가능 -> 그래서 0~1, 2~3, 4~5, 6~7로 해서 쪼개서 검사필요
*/

#include<iostream>
#include<vector>

using namespace std;

//발상 : 그냥 1초부터 최대 초로 늘리면?
//그 이상은 무조건 안 되니까, 초과니까

int getMaxTerm(const vector<int> interrupt, int max_interrupt)
{
    int answer = 1;
    bool isErr = false;
    int max_time = interrupt[interrupt.size()-1];
    while(!isErr)
    {
        
    }
    return answer;
}

int main()
{
    cout<<getMaxTerm({3, 7, 8}, 2)<<endl;           //out : 8
    cout<<getMaxTerm({3, 4, 8}, 1)<<endl;           //out : 4
    cout<<getMaxTerm({1, 2, 3, 4, 5, 6}, 2)<<endl;  //out : 2
    cout<<getMaxTerm({3, 4, 7, 8}, 1)<<endl;        //out : 2
}