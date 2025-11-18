#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    string arr = to_string(n);
    sort(arr.rbegin(), arr.rend());
    return stoll(arr);
}