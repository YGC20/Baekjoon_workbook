#include <string>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
bool operator()(int a, int b) { return a > b; }
};

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, cmp> sco;
    for(auto& s : scoville) { sco.push(s); }
    
    while(sco.top() < K) {
        if(sco.size() < 2) { answer = -1; break; }
        int a = sco.top(); sco.pop();
        int b = sco.top(); sco.pop();
        sco.push((a + (b * 2)));
        answer++;
    }
    return answer;
}