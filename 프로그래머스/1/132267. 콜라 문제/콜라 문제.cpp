#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n)
{
    int result = 0;
    while(n >= a) {
        int mod = n % a;
        n /= a;
        result += (n * b);
        n = (n * b) + mod;
    }
    return result;
}