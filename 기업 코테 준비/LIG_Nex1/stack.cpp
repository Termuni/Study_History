#include<stack>
#include<iostream>
#include<vector>


using namespace std;

int main()
{
    vector<stack<int>> test;
    stack<int> check;
    for(int i=0; i<5; ++i)
    {
        test.push_back(check);
        for(int j=i; j<8; ++j)
        {
            test[i].push(j);
        }
    }

    for(int i=0; i<test.size(); ++i)
    {
        int temp_size = test[i].size();
        cout<<"Cycle "<<i+1<<" : ";
        for(int j=0; j<temp_size; ++j)
        {
            cout<<test[i].top()<<' ';
            test[i].pop();
        }
        cout<<'\n';
    }
}