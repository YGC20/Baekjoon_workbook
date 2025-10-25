#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(),routes.end(),[](const vector<int>& a, const vector<int>& b){return a[1]<b[1];});
    int camPos = -30001, camCnt = 0;
    for(const vector<int> car:routes){
        if(camPos<car[0]){
            camPos = car[1];
            camCnt++;
        }
    }
    return camCnt;
}