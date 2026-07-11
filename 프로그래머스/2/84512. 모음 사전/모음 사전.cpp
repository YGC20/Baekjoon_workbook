#include <string>
#include <vector>
using namespace std;

int result = 0;
vector<char> words = {'A','E','I','O','U'};
vector<char> setting;
bool found = false;

void dfs(int len, string s)
{
    int i;
    if(found) {
        return;
    }
    
    string curr(setting.begin(), setting.end());
    if(curr == s) {
        found = true;
        return ;
    }
    
    if(len == 5) {
        return ;
    }
    for(i=0; i<5; ++i) {
        setting.push_back(words[i]);
        result++;
        dfs(len+1, s);
        if(found) {
            return ;
        }
        setting.pop_back();
    }
}

int solution(string word)
{
    result = 0;
    found = false;
    dfs(0,word);
    return result;
}