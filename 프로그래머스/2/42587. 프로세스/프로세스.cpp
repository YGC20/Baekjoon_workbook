#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location)
{
    int answer = 0;
    queue<pair<int,int>> que;
    priority_queue<int> pq;
    for(int i=0; i<static_cast<int>(priorities.size()); ++i) {
        que.push({priorities[i], i});
        pq.push(priorities[i]);
    }
    
    while(!que.empty()) {
        int pri = que.front().first, loc = que.front().second;
        int pqpri = pq.top();
        if(pri == pqpri) {
            answer++;
            if(loc == location) { break; }
            que.pop();
            pq.pop();
        }
        else {
            que.push(que.front()); que.pop();
        }
    }
    return answer;
}