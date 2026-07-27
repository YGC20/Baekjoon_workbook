#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b) { return b? gcd(b, a%b) : a; }

int lcm(int a, int b, int gcdAB) { return (a * b) / gcdAB; }

vector<int> solution(int n, int m)
{
    int gcdResult = gcd(n, m);
    int lcmResult = lcm(n, m, gcdResult);
    vector<int> result = { gcdResult, lcmResult };
    return result;
}