#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(vector<vector<int> > land)
{
    int i, j, k;
    int len = land.size();
    
    for(i=1; i<len; ++i) {
        for(j=0; j<4; ++j) {
            int maxVal = 0;
            for(k=0; k<4; ++k) {
                if(j==k) continue;
                maxVal = max(maxVal, land[i-1][k]);
            }
            land[i][j] += maxVal;
        }
    }
    
    int result = 0;
    for(i=0; i<4; ++i) {
        result = max(result, land[len-1][i]);
    }
    return result;
}