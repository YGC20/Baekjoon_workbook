#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<int> arr, int k)
{
    vector<int> result;
    unordered_set<int> check;
    
    for(int num : arr) {
        if(check.find(num)==check.end()) {
            result.push_back(num);
            check.insert(num);
        }
        if(result.size()==k) break;
    }
    
    while(result.size()<k)
        result.push_back(-1);
    return result;
}