#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg)
{
    int i;
    string ch;
    vector<int> answer;
    map<string, int> dir;
    for(i=0; i<26; ++i) {
        ch = 'A' + i;
        dir[ch] = i+1;
    }
    
    string word = "";
    int num, lastNum = dir.size() + 1;
    for(i=0; i<msg.length(); ++i) {
        word += msg[i];
        num = dir[word];
        
        while(dir.find(word) != dir.end()) {
            word += msg[++i];
            if(dir.find(word) == dir.end()) {
                dir[word] = lastNum++;
                i--;
                break;
            } else { num = dir[word]; }
        }
        answer.push_back(num);
        word.clear();
    }
    return answer;
}