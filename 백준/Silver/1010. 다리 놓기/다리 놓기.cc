#include <iostream>
using namespace std;

int T;
int dp[31][31];

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	
	for(int i=0; i<=30; i++){
		dp[i][0] = 1;
		dp[i][i] = 1;
	}

	for(int m=1; m<=30; m++){
		for(int n=1; n<m; n++){
			dp[m][n] = dp[m-1][n-1]+dp[m-1][n];
		}
	}

	for(int i=0; i<T; i++){
		int N, M;
		cin >> N >> M;
		cout << dp[M][N] << "\n";
	}
	return 0;
}