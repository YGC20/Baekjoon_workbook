#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> p_priorities, int p_location)
{
    queue<pair<int,int>> que;
    priority_queue<int> pq;
    for(int i=0; i<p_priorities.size(); i++) {
        que.push({p_priorities[i], i});
        pq.push(p_priorities[i]);
    }
    int answer = 0;
    while(!que.empty()) {
        int currentP = que.front().first;
        int currentIdx = que.front().second;
        que.pop();
        
        if(currentP==pq.top()) {
            answer++;
            pq.pop();
            if(currentIdx==p_location) {
                break;
            }
        }
        else {
            que.push({currentP, currentIdx});
        }
    }
    return answer;
}