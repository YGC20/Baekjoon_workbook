#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    while(b>0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    int denom = (denom1 * denom2) / gcd(denom1, denom2);
    int numer = (numer1 * (denom / denom1)) + (numer2 * (denom / denom2));
    
    int gcdDN = gcd(denom, numer);
    return { numer/gcdDN, denom/gcdDN };
}