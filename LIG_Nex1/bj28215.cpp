// https://www.acmicpc.net/problem/28215

#define MAXIMUM 200000

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int>> houses;
vector<int> distances;
int n, k; //n = number of houses, k = max number of 대피소

int Get_Distance(int p1, int p2, int p3){
    int ans = 0;
    for(int i=0; i<n; ++i) {
        ans = max(ans, min({abs(houses[i].first - houses[p1].first) + abs(houses[i].second - houses[p1].second),
                            abs(houses[i].first - houses[p2].first) + abs(houses[i].second - houses[p2].second),
                            abs(houses[i].first - houses[p3].first) + abs(houses[i].second - houses[p3].second)}));
    }
    return ans;
}

int main(){
    cin >> n >> k;
    for(int i=0; i<n; ++i){
        int x, y;
        cin>>x>>y;
        houses.push_back(make_pair(x,y));
    }
    int ans = MAXIMUM;
    // 1, 2, 3일 경우를 나누어 3단 for loop 진행
    // 1, 2, 3일 때로 calc함수를 나누어 짜지 않고 간단하게 인자를 동일시 시키는 방법을 택함 
    if(k==1) {
        for(int i=0; i<n; ++i) 
        {
            distances.push_back(Get_Distance(i, i, i));
            ans = min(ans, Get_Distance(i, i, i));
        }
    }
    else if(k==2) {
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                distances.push_back(Get_Distance(i, j, j));
                ans = min(ans, Get_Distance(i, j, j));
            }
        }
    }   
    else if(k==3) {
        for(int i=0; i<n; ++i) {
            for(int j=i; j<n; ++j) {
                for(int k=j; k<n; ++k) {
                    distances.push_back(Get_Distance(i, j, k));
                    ans = min(ans, Get_Distance(i, j, k));
                }
            }
        }
    }
    // for(int i=0; i<distances.size(); ++i){
    //     cout<<distances[i]<<' ';
    // }
    // cout <<'\n';
    cout << ans << '\n';
}