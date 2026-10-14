#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool diff(const string& a, const string& b)
{
    int diffCnt = 0;
    int n = static_cast<int>(a.size());
    for(int i=0; i<n; ++i) {
        if(a[i] != b[i]) { diffCnt++; }
    }
    if(diffCnt == 1) { return true; }
    return false;
}

void changeWords(string current, string target,
                 vector<string>& words,
                 vector<bool>& visited,
                 int& ans, int cnt)
{
    if(ans<=cnt) { return; }
    if(current == target) { ans = min(ans, cnt); return; }
    int len = static_cast<int>(words.size());
    for(int i=0; i<len; ++i) {
        if(diff(words[i], current) && !visited[i]) {
            visited[i] = true;
            changeWords(words[i], target, words, visited, ans, cnt + 1);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    int answer = 0;
    bool ctk = true;
    int len = static_cast<int>(words.size());
    for(int i=0; i<len; ++i) {
        if(target == words[i]) { ctk = false; break; }
    }
    if(ctk) { return answer; }
    
    answer = len;
    vector<bool> visited(len, false);
    changeWords(begin, target, words, visited, answer, 0);
    
    return answer;
}