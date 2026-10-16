#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location)
{
    int i, answer = 0;
    queue<int> que;
    priority_queue<int> pq;
    for(i=0; i<priorities.size(); ++i) { que.push(i); pq.push(priorities[i]); }
    
    while(!pq.empty()) {
        int prio = pq.top(); pq.pop();
        int idx = que.front();
        while(!que.empty() && prio != priorities[idx]) {
            que.push(idx); que.pop();
            idx = que.front();
        }
        que.pop();
        answer++;
        if(idx == location) { break; }
    }
    
    return answer;
}