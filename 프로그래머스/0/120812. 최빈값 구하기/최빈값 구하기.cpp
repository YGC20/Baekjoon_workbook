#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<int> array) {
    map<int, int> nums;
    for(auto x :array)
        nums[x]++;
    
    int max = 0;
    int answer = 0;
    bool check = false;
    for(auto const& [n, c] : nums) {
        if(c>max) {
            max = c;
            answer = n;
            check = false;
        }
        else if(c==max) {
            check = true;
        }
    }
    return (check?-1:answer);
}