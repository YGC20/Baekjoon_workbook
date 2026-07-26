#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr)
{
    arr.erase(arr.begin() + (min_element(arr.begin(), arr.end())-arr.begin()));
    if(arr.empty()) arr.push_back(-1);
    return arr;
}