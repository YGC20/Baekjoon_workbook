#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int s : scoville) {
        pq.push(s);
    }
    
    int count = 0;
    while(!pq.empty()) {
        if(pq.top() >= K || pq.size() < 2) break;
        int f = pq.top(); pq.pop();
        int s = pq.top(); pq.pop();
        int ms = f + (s * 2);
        pq.push(ms);
        count++;
    }
    if(pq.top()<K) return -1;
    return count;
}