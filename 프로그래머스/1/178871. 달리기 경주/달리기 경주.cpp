#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string,int> race;
    int ps = (int)players.size();
    for(int i=0;i<ps;++i)
        race[players[i]] = i;
    for(const string& name:callings){
        int i = race[name];
        if(i==0) continue;
        string& front = players[i-1];
        string& back = players[i];
        swap(front, back);
        race[front] = i-1;
        race[back] = i;
    }
    return players;
}