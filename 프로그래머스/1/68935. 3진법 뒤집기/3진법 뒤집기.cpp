#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n)
{
    int answer = 0;
    string ternary = "";
    while(n >= 3) {
        ternary += to_string(n % 3);
        n /= 3;
    }
    ternary += to_string(n);

    int i, mul = 1;
    int len = (int)ternary.length() - 1;
    for(i=0; i<len; ++i) { mul *= 3; }

    for(i=0; i<(int)ternary.length(); ++i) {
        answer += (ternary[i] - '0') * mul;
        mul /= 3;
    }

    return answer;
}