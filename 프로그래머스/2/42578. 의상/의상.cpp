#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string,int> cody;
    for(const auto& data:clothes){
        cody[data[1]]++;
    }
    int val = 1;
    for(const auto& [data,cnt]:cody){
        val*=(cnt+1);
    }
    return val-1;
}