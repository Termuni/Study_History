//https://www.acmicpc.net/problem/2309

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> heights(9);

int main()
{
    bool isDone = false;
    int tot = 0;
    int sp1, sp2;
    for(int i = 0; i<9; ++i)
    {
        int h;
        cin>>h;
        heights[i]=h;
        tot+=h;
    }
    tot -= 100;
    sort(heights.begin(), heights.end(), less<>());
    for(int i=0; i<8; ++i)
    {
        if(isDone)
        {
            break;
        }
        for(int j=1; j<9; ++j)
        {
            if((heights[i] + heights[j])==tot)
            {
                heights[i]=-1;
                heights[j]=-1;
                isDone = true;
                break;
            }
        }
    }
    sort(heights.begin(), heights.end(), greater<>());
    heights.pop_back(); heights.pop_back();
    sort(heights.begin(), heights.end(), less<>());
    for(int i=0; i<7; ++i)
    {
        cout<<heights[i]<<'\n';
    }
}
