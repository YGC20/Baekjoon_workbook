// 15991 : 1,2,3 더하기 6
#include <iostream>
#include <vector>
#define MOD 1000000009
using namespace std;
typedef long long ll;

vector<ll> solv(void)
{
	vector<ll> dp(100001, 0);
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 100000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}
	vector<ll> result(100001, 0);
	result[1] = 1; result[2] = 2; result[3] = 2;
	for (int i = 4; i <= 100000; i++) {
		if (i % 2 == 0) {
			result[i] = (dp[i / 2] + dp[(i - 2) / 2]) % MOD;
		}
		else {
			result[i] = (dp[(i - 1) / 2] + dp[(i - 3) / 2]) % MOD;
		}
	}
	return result;
}

int main(int argc, char* argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	vector<ll> result = solv();

	int testCase; cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		int num; cin >> num;
		cout << result[num] << "\n";
	}
	return 0;
}