#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int len, int w, vector<int> v)
{
    int idx = 0, time = 0, sum = 0;
    queue<int> que;
    vector<pair<int, int>> truck(10010);
    do {
        time++;
        if(!que.empty() && (truck[que.front()].second + len) <= time) {
            sum -= truck[que.front()].first;
            que.pop();
        }
        
        if(idx < v.size() && sum + v[idx] <= w) {
            sum += v[idx];
            que.push(idx);
            truck[idx].first = v[idx];
            truck[idx].second = time;
            idx++;
        }
    } while(!que.empty());
    return time;
}