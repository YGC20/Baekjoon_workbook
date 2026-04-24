#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int a, int b, int c, int d) {
    vector<int> dice(7, 0);
    dice[a]++, dice[b]++, dice[c]++, dice[d]++;
    
    int cnt = 0;
    vector<pair<int,int>> num;
    for(int i=0; i<7; i++)
        if(dice[i]!=0) {
            cnt++;
            num.push_back({i, dice[i]});
        }
    
    sort(num.begin(), num.end(), [](const pair<int,int>& a, const pair<int,int>& b){ 
        if(a.second==b.second) return a.first<b.first; return a.second>b.second;
        });
    if(cnt==4) {
        return num[0].first;
    }
    else if(cnt==3) {
        int q  = num[1].first;
        int r  = num[2].first;
        return q*r;
    }
    else if(cnt==2) {
        if(num[0].second==3) {
            int p = num[0].first;
            int q = num[1].first;
            return (10*p+q)*(10*p+q);
        }
        else {
            int p = num[0].first;
            int q = num[1].first;
            return (p+q)*((p-q>0)?p-q:q-p);
        }
    }
    else if(cnt==1) {
        return 1111 * num[0].first;
    }
}