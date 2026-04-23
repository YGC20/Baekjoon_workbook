#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int idx = 0;
    vector<int> stk;
    while(idx<arr.size()) {
        if(stk.empty()) {
            stk.push_back(arr[idx]);
            idx++;
        }
        else {
            if(stk.back()<arr[idx]) {
                stk.push_back(arr[idx]);
                idx++;
            }
            else {
                stk.pop_back();
            }
        }
    }
    return stk;
}