#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    int userNum = 0, turn = 0;
    vector<string> wordStack;
    wordStack.push_back(words[0]);
    for(int i=1; i<words.size(); ++i){
        if(find(wordStack.begin(),wordStack.end(),words[i])!=wordStack.end()||
           words[i-1].back()!=words[i].front()){
            turn = ((i+1)%n==0)?(i+1)/n:((i+1)/n)+1;
            userNum = ((i+1)%n==0)?n:(i+1)%n;
            break;
        }
        wordStack.push_back(words[i]);
    }
    vector<int> answer={userNum, turn};
    return answer;
}