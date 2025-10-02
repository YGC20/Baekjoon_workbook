#include <bits/stdc++.h>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    if(discount.size()<10)  return 0;
    
    unordered_map<string,int> need;
    for(int i=0;i<(int)want.size();++i) need[want[i]]=number[i];
    unordered_map<string,int> win;
    for(int i=0;i<10;++i)   win[discount[i]]++;
    
    auto ok = [&](){
        for(auto &p:need){
            const string &item=p.first;
            int req=p.second;
            if(win[item]<req)   return false;
        }
        return true;
    };
    
    int answer = 0;
    if(ok())    answer++;
    
    for(int i=10;i<(int)discount.size();++i){
        string out = discount[i-10];
        if(--win[out]==0)   win.erase(out);
        
        string in = discount[i];
        win[in]++;
        
        if(ok())    answer++;
    }
    return answer;
}