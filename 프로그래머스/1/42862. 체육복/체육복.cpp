#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    vector<int> user(n, 1);
    for(auto& u : reserve) { user[u-1] += 1; }
    for(auto& u : lost) { user[u-1] -= 1; }
    
    if(user[0] == 0 && user[1] == 2) { user[1] -= 1; user[0] += 1; }
    if(user[n-1] == 0 && user[n-2] == 2) { user[n-2] -= 1; user[n-1] += 1; }
    for(int i=1; i<n-1; ++i) {
        if(user[i] != 0) { continue; }
        int front = i - 1, back = i + 1;
        if(user[front] == 2) { user[front] -= 1; user[i] += 1; }
        if(user[i] == 0 && user[back] == 2) { user[back] -= 1; user[i] += 1; }
    }
    
    int answer = 0;
    for(auto& u : user) {
        if(u != 0) { answer++; }
    }
    return answer;
}