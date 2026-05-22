#include <iostream>
using namespace std;

const long long MOD = 998244353;

long long getSum(long long n)
{
	if (n % 2 == 0)
		return ((n / 2) % MOD)*((n + 1) % MOD) % MOD;
	else
		return (n % MOD) * (((n + 1) / 2) % MOD) % MOD;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int TC; cin >> TC;
	for (int testCase = 1; testCase <= TC; testCase++) {
		long long A, B, C;
		cin >> A >> B >> C;

		long long sumA = getSum(A);
		long long sumB = getSum(B);
		long long sumC = getSum(C);

		long long ans = (sumA*sumB) % MOD;
		ans = (ans*sumC) % MOD;

		cout << ans << "\n";
	}
	return 0;
}