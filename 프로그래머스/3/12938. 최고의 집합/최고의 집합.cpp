#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s)
{
    int i;
    vector<int> result;
    int num = s / n;
    if(num == 0) { result.push_back(-1); return result; }
    
    for(i=0; i<n; ++i) {
        result.push_back(num);
    }
    int left = s % n;
    if(left != 0) {
        for(i=0; i<left; ++i) {
            result[i]++;
        }
        sort(result.begin(), result.end());
    }
    return result;
}