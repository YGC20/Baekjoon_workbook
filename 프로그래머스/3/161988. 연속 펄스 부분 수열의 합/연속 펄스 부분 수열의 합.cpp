#include <string>
#include <vector>
using namespace std;
typedef long long ll;

ll solution(vector<int> sequence)
{
    int i;
    int len = sequence.size();
    ll dpA = sequence[0];
    ll dpB = -sequence[0];
    ll maxVal = (dpA>dpB)?dpA:dpB;
    
    for(i=1; i<len; ++i) {
        int num = sequence[i];
        int currA = (i%2==0)?num:-num;
        int currB = (i%2==0)?-num:num;
        
        dpA = ((dpA+currA)>currA)?(dpA+currA):currA;
        dpB = ((dpB+currB)>currB)?(dpB+currB):currB;
        
        if(dpA>maxVal) {
            maxVal = dpA;
        }
        if(dpB>maxVal) {
            maxVal = dpB;
        }
    }
    return maxVal;
}