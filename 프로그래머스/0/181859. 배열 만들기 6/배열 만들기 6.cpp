#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> stk;
    stk.push_back(arr[0]);
    for(int i=1; i<arr.size(); i++) {
        if(stk.empty()) 
            stk.push_back(arr[i]);
        else {
            if(stk.back()==arr[i])
                stk.pop_back();
            else
                stk.push_back(arr[i]);
        }
    }
    if(stk.empty()) stk.push_back(-1);
    return stk;
}