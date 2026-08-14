#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges)
{
    int answer = 0;
    int len = message.length();
    
    vector<bool> visited(len, false);
    for(const vector<int>& sr : spoiler_ranges) {
        for(int i=sr[0]; i<=sr[1]; ++i) {
            if(i < len) { visited[i] = true; }
        }
    }
    
    map<string, int> totalCnt;
    map<string, int> spoiledCnt;
    
    int idx = 0;
    while(idx < len) {
        if(message[idx] == ' ') { ++idx; continue; }
        
        string word = "";
        bool isSpoiled = false;
        while(idx < len && message[idx] != ' ') {
            if(visited[idx]) { isSpoiled = true; }
            word += message[idx++];
        }
        totalCnt[word]++;
        if(isSpoiled) { spoiledCnt[word]++; }
    }
    
    for(const auto& tc : totalCnt) {
        string w = tc.first;
        int cnt = tc.second;
        if(cnt == spoiledCnt[w]) { answer++; }
    }
    return answer;
}