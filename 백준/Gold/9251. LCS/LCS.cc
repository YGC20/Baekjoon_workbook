#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void){
    string str1, str2;
    cin >> str1 >> str2;
    int str1Size = str1.size(), str2Size = str2.size();
    vector<vector<int>> dp(str1Size+1, vector<int>(str2Size+1, 0));
    int i, j;
    for(i=1; i<=str1Size; ++i){
        for(j=1; j<=str2Size; ++j){
            if(str1[i-1]==str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = (dp[i-1][j]>dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
        }
    }
    cout << dp[str1Size][str2Size] << endl;
    return 0;
}