// 16493 : 최대 페이지 수
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solv(void) {
	int days, chapters;
	cin >> days >> chapters;

	vector<int> dp(days + 1, 0);

	for (int i = 0; i < chapters; i++) {
		int day, page;
		cin >> day >> page;
		for (int j = days; j >= day; j--) {
			dp[j] = max(dp[j], dp[j - day] + page);
		}
	}

	return dp[days];
}

int main(int argc, char* argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	cout<<solv()<<"\n";
	
	return 0;
}