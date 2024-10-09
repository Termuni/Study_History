//https://www.acmicpc.net/problem/2609

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> num1, num2;
int n1, n2;

int Get_Min_Mul()
{
    int max_n = max(n1, n2);
    for(int i=1;i<=max_n;++i)
    {
        if(n1%i==0)
        {
            num1.push_back(i);
        }
        if(n2%i==0)
        {
            num2.push_back(i);
        }
    }
    max_n = 1;
    for(int i=0;i<num1.size();++i)
    {
        for(int j=0; j<num2.size();++j)
        {
            if(num1[i] == num2[j])
            {
                max_n = max(max_n, num1[i]);
            }
        }
    }
    return max_n;
}

int Get_Max_Mul()
{
    int tot = 1;
    int divider = 2;
    int target1 = n1, target2 = n2;
    while((divider <= target1) && (divider <= target2)){
        if((target1%divider == 0) && (target2%divider == 0))
        {
            tot*=divider;
            target1 /= divider;
            target2 /= divider;
        }
        else
        {
            ++divider;
        }
    }
    tot = tot * target1 * target2;
    return tot;
}

int main(){
    cin>>n1>>n2;
    int min_mul = Get_Min_Mul();
    int max_mul = Get_Max_Mul();
    cout<<min_mul <<'\n'<<max_mul<<'\n';
}