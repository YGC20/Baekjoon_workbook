#include <string>
#include <vector>
using namespace std;

int Bigger(int a, int b) { if(a > b) return a; return b; }

int solution(vector<int> money)
{
    int i;
    int len = money.size();
    vector<int> DP0(len);
    vector<int> DP1(len);
    DP0[0] = money[0];
    DP0[1] = DP0[0];
    DP1[0] = 0;
    DP1[1] = money[1];
    
    for(i=2; i<len-1; ++i) {
        DP0[i] = Bigger((DP0[i-2] + money[i]), DP0[i-1]);
    }
    
    for(i=2; i<len; ++i) {
        DP1[i] = Bigger((DP1[i-2] + money[i]), DP1[i-1]);
    }
    
    return Bigger(DP0[len-2], DP1[len-1]);
}