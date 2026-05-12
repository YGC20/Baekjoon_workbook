#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> lines)
{
    vector<int> count(201, 0);
    
    for(auto l : lines) {
        for(int i=l[0]; i<l[1]; i++) {
            count[i+100]++;
        }
    }
    
    int cnt = 0;
    for(int i=0; i<201; i++) {
        if(count[i]>=2) {
            cnt++;
        }
    }
    return cnt;
}