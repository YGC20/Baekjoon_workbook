#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char** argv)
{
	int T; cin >> T;
    for(int tc=1; tc<=T; ++tc) {
        double sum = 0;
        vector<int> nums(10, 0);
        for(int i=0; i<10; ++i) {
            cin >> nums[i];
            sum += nums[i];
        }
        sort(nums.begin(), nums.end());
        sum -= (double)(nums.front() + nums.back());
        sum /= 8.0;
        cout << "#" << tc << " " << floor(sum + 0.5) << endl;
    }
    return 0;
}