//https://www.acmicpc.net/problem/9935

/* 
//시간 초과로 인해 틀림
// #include<iostream>
// #include<string>

// using namespace std;

// string input;
// string bomb;

// int main(){
//     cin>>input>>bomb;
//     while(input.find(bomb) != string::npos){
//         int pos = input.find(bomb);
//         input.erase(pos,bomb.size());
//     }
//     if(input.size()!=0){
//         cout<<input;
//     }
//     else{
//         cout<<"FRULA";
//     }
// }
*/

#define MAXLENGTH 1000000
#include<iostream>
#include<string>

using namespace std;

string input, bomb;

int main(){
    cin>>input>>bomb;
    int bomb_size = bomb.size();
    char answer[MAXLENGTH];
    int input_pos = 0;
    
    for(int i=0; i<input.size(); ++i)
    {
        if(input_pos >= bomb_size)
        {
            bool isBomb = true;
            for(int j=0; j<bomb_size; ++j)
            {
                if(answer[input_pos-bomb_size+j] != bomb[j])
                {
                    isBomb = false;
                    break;
                }
            }
            if(isBomb)
            {
                for(int j=0; j<bomb_size; ++j)
                {
                    answer[input_pos-bomb_size+j] = '-';
                }
                input_pos -= bomb_size;
            }
        }
        answer[input_pos] = input[i];
        ++input_pos;
    }
    if(input_pos >= bomb_size)
    {
        bool isBomb = true;
        for(int j=0; j<bomb_size; ++j)
        {
            if(answer[input_pos-bomb_size+j] != bomb[j])
            {
                isBomb = false;
                break;
            }
        }
        if(isBomb)
        {
            for(int j=0; j<bomb_size; ++j)
            {
                answer[input_pos-bomb_size+j] = '-';
            }
            input_pos -= bomb_size;
        }
    }
    string output;
    for(int i=0; i<input_pos; ++i){
        output += answer[i];
    }
    if(answer[0] == '-'){
        cout<<"FRULA";
    }
    else{
        cout<<output;
    }
    
}