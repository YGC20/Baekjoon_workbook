#include <string>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

ll solution(int n, vector<int> works)
{
    priority_queue<int> pq;
    for(auto w : works) {
        pq.push(w);
    }
    
    while(!pq.empty() && n>0) {
        int num = pq.top() - 1; pq.pop();
        if(num > 0) {
            pq.push(num);
        }
        n--;
    }
    
    ll result =0;
    while(!pq.empty()) {
        int num = pq.top(); pq.pop();
        result += (num * num);
    }
    return result;
}