//연산자 끼워넣기
//https://www.acmicpc.net/problem/14888

// 1 2 3 4 5 6
// 숫자 개수 : n개
// 연산자 개수 : n-1개
// 숫자 크기 : 1~100
// 최대 가짓수 : n-1 P n-1?
// 5 6 / 0 0 1 0  -> 1P0
// 5 6 7 / 1 0 1 0 -> 2 P 

//최대 가짓수 : 92400가지 (11! / (3! * 3! * 3!*/ 2!) )
#define MAXVALUE (2100000000)
#define MINVALUE (-2100000000)
#define MAXCOMBINATION 92401
#include<iostream>
#include<vector>

int values[MAXCOMBINATION];

using namespace std;

vector<int> a;

int main()
{

}