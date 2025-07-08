#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solution(int n){
    vector<int> wines(n + 1, 0);
    vector<int> dp(n + 1, 0);
    for(int i = 1; i <= n; i++)
        cin >> wines[i];

    dp[1] = wines[1];
    if(n>1)
        dp[2] = wines[1] + wines[2];

    for(int i = 3; i <= n; i++) {
        int case1 = dp[i-1];
        int case2 = dp[i-2] + wines[i];
        int case3 = dp[i-3] + wines[i-1] + wines[i];
        dp[i] = max({case1, case2, case3});
    }
    
    cout << dp[n] << "\n";
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    solution(N);
    return 0;
}
