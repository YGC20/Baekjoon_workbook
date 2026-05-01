#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int solution(vector<int> array, int n)
{
    sort(array.begin(), array.end());
    
    auto it = lower_bound(array.begin(), array.end(), n);
    
    if(it==array.begin()) return *it;
    if(it==array.end()) return *(it-1);
    
    int rightVal = *it;
    int leftVal = *(it-1);
    return (abs(rightVal-n)<abs(leftVal-n)) ? rightVal : leftVal;
}