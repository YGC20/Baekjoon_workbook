#include <vector>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map)
{
    int i, j;
    vector<vector<vector<int>>> dp(m+1, vector<vector<int>>(n+1, vector<int>(2,0)));
    dp[1][1][0] = 1;
    
    for(i=1; i<=m; ++i) {
        for(j=1; j<=n; ++j) {
            int mapStatus = city_map[i-1][j-1];
            if(mapStatus == 1) {
                continue;
            }
            
            if(mapStatus == 0) {
                if(i+1 <= m) {
                    dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0] + dp[i][j][1]) % MOD;
                }
                if(j+1 <= n) {
                    dp[i][j+1][1] = (dp[i][j+1][1] + dp[i][j][0] + dp[i][j][1]) % MOD;
                }
            }
            else if(mapStatus == 2) {
                if(i+1 <= m) {
                    dp[i+1][j][0] = (dp[i+1][j][0] + dp[i][j][0]) % MOD;
                }
                if(j+1 <= n) {
                    dp[i][j+1][1] = (dp[i][j+1][1] + dp[i][j][1]) % MOD;
                }
            }
        }
    }
    return (dp[m][n][0] + dp[m][n][1]) % MOD;
}