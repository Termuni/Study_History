#define MAXNUM 10
#include<stdio.h>
#include<math.h>



int Char_To_Int(char num[MAXNUM], int max_pos)
{
    int ans = 0;
    for(int i=0; i<MAXNUM; ++i)
    {
        ans += (int)(num[i] - '0') * pow(10, max_pos - i - 1);
    }
    return ans;
}


int main()
{
    char num[MAXNUM] = {'5', '1', '0', '0', '0', '0', '0', '0', '0', '0'};
    
    printf("%d",Char_To_Int(num, 0));
}