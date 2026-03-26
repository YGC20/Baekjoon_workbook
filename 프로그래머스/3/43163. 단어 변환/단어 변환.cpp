#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int result = 50;
bool visited[51];

bool check_diff(string a, string b)
{
    int cnt = 0;
    for(int i=0; i<a.size(); ++i) {
        if(a[i]!=b[i]) {
            cnt++;
        }
    }

    if(cnt==1) {
        return true;
    }
    return false;
}

void dfs(string current, string target, vector<string> words, int idx)
{
    if(result<=idx) {
        return;
    }

    if(current==target) {
        result = min(result,idx);
        return;
    }

    for(int i=0; i<words.size(); ++i) {
        if(check_diff(current, words[i]) && !visited[i]) {
            visited[i]=true;
            dfs(words[i], target, words, idx+1);
            visited[i]=false;
        }
    }
}

int solution(string begin, string target, vector<string> words)
{
    dfs(begin, target, words, 0);

    if(result==50) {
        return 0;
    }
    return result;
}