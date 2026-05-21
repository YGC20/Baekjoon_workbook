#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char** argv)
{
	int T;
	cin >> T;

	for (int testCase = 1; testCase <= T; testCase++) {
		int N, M, K;
		cin >> N >> M >> K;
		
		vector<int> times;
		for (int i = 0; i < N; i++) {
			int time;
			cin >> time;
			times.push_back(time);
		}
		sort(times.begin(), times.end());
		
		bool checkPossible = true;

		for (int i = 0; i < N; i++) {
			int t = times[i];
			int cur = (t / M) * K - i;
			if (cur <= 0) {
				checkPossible = false;
				break;
			}
		}

		if (checkPossible) cout << "#" << testCase << " Possible\n";
		else cout << "#" << testCase << " Impossible\n";
	}

	return 0;
}

