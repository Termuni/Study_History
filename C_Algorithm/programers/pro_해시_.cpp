// https://school.programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>
#include <unordered_map>


using namespace std;

bool Compare(string object, string target)
{
    //object size <= target
    for(int i=0; i<object.size(); ++i)
    {
        if(target[i] != object[i]) return true;
    }
    return false;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    unordered_map<string, int> numbers;
    int idx = 0, input_size = phone_book.size();;
    while (answer && idx<input_size)
    {
        string phone_num = phone_book[idx];
        for(auto number : numbers)
        {
            if(number.first.size() >= phone_num.size())
            {
                //앞자리 같은지 확인
                answer = Compare(phone_num, number.first);
            }
            else
            {
                //앞자리 같은지 확인
                answer = Compare(number.first, phone_num);
            }
            if(!answer) break;
        }
        if(numbers.find(phone_num) == numbers.end())
        {
            numbers.insert(make_pair(phone_num, phone_num.size() ) );
        }
        ++idx;
    }
    
    return answer;
}