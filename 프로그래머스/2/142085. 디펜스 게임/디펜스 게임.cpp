#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int k, vector<int> enemy)
{
    int i;
    priority_queue<int> pq;
    for(i=0; i<enemy.size(); ++i) {
        n -= enemy[i];
        pq.push(enemy[i]);
        while(n<0 && k>0 && !pq.empty()) {
            n += pq.top(); pq.pop();
            k -= 1;
        }
        if(n<0) { break; }
    }
    return i;
}