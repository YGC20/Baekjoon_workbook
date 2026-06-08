#if 01
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int>& nums, int idx, int b, int sum, int* min)
{
	if (sum >= b && *min > sum) *min = sum;
	if (nums.size() == idx) return;
	dfs(nums, idx + 1, b, sum+nums[idx], min);
	dfs(nums, idx + 1, b, sum, min);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int N, B;
	cin >> N >> B;

	int min = 0;
	vector<int> cows(N);
	for (int i = 0; i < N; ++i) {
		cin >> cows[i];
		min += cows[i];
	}
	sort(cows.begin(), cows.end());

	dfs(cows, 0, B, 0, &min);
	cout << (min - B) << "\n";

	return 0;
}
#endif