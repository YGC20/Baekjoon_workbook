#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    int i;
    queue<int> que;
    for(i=0; i<progresses.size(); ++i) {
        int job = ((100 - progresses[i]) / speeds[i]) + 
            ((100 - progresses[i]) % speeds[i] == 0 ? 0 : 1);
        que.push(job);
    }
    
    int todo = (!que.empty() ? que.front() : 0); que.pop();
    vector<int> answer;
    int idx = 0; answer.push_back(1);
    while(!que.empty()) {
        int curr = que.front(); que.pop();
        if(todo < curr) {
            todo = curr;
            answer.push_back(1);
            idx++;
        } else {
            answer[idx]++;
        }
    }
    return answer;
}