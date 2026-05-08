#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers)
{
    sort(numbers.begin(), numbers.end());
    int len = numbers.size();
    int fn = numbers[0] * numbers[1];
    int ln = numbers[len-1] * numbers[len-2];
    return max(fn, ln);
}