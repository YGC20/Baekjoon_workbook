#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    unordered_map<char,int> score;
    for(char c:string("RTCFJMAN")) score[c]=0;
    
    for(size_t i=0;i<survey.size();++i){
        char a = survey[i][0];
        char b = survey[i][1];
        int diff = choices[i]-4;
        
        if(diff<0) score[a] += -diff;
        else if(diff>0) score[b] += diff;
    }
    
    auto pick = [&](char x, char y){
        return (score[x]>=score[y]?x:y);
    };
    
    string answer;
    answer+=pick('R','T');
    answer+=pick('C','F');
    answer+=pick('J','M');
    answer+=pick('A','N');
    return answer;
}