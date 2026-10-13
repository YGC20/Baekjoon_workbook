#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{
    vector<int> answer;
    int len = static_cast<int>(progresses.size());
    
    queue<int> que;
    for(int i=0; i<len; ++i) {
        int job = ((100 - progresses[i]) / speeds[i]) + 
            ((100 - progresses[i]) % speeds[i] == 0 ? 0 : 1);
        que.push(job);
    }
    
    int idx = 0;
    int time = (!que.empty() ? que.front() : 0); que.pop();
    answer.push_back(1);
    while(!que.empty()) {
        int curr = que.front(); que.pop();
        if(curr > time) {
            time = curr;
            answer.push_back(1);
            idx++;
        } else {
            answer[idx]++;
        }
    }
    return answer;
}