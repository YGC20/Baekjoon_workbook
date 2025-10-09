#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> players, int m, int k) {
    const int n = (int)players.size();
    int extra = 0;
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i=0;i<n;++i){
        while(!pq.empty()&&pq.top()==i){
            pq.pop();
            --extra;
        }
        int req = players[i]/m;
        if(req>extra){
            int need = req-extra;
            extra+=need;
            answer+=need;
            for(int t=0;t<need;++t) pq.push(i+k);
        }
    }
    return answer;
}