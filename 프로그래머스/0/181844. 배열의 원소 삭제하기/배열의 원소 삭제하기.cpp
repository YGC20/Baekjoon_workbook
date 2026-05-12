#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list)
{
    vector<int> result;
    unordered_set<int> dl(delete_list.begin(), delete_list.end());
    
    for(int num : arr) {
        if(dl.find(num) == dl.end()) {
            result.push_back(num);
        }
    }
    return result;
}