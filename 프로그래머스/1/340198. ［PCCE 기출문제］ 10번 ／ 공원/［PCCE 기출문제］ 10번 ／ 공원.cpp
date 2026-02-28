#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int rows = park.size();
    int cols = park[0].size();
    
    vector<vector<int>> dp(rows,vector<int>(cols,0));
    int max_cnt = 0;
    
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            if(park[i][j]=="-1") {
                if(i==0 || j==0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
                }
                max_cnt = max(max_cnt, dp[i][j]);
            }
        }
    }
    
    sort(mats.begin(), mats.end(), [](const int& a, const int& b){ return a>b; });
    for(int m : mats) {
        if(m<=max_cnt) {
            return m;
        }
    }
    return -1;
}