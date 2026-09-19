#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

string convertToBase(int n, int k)
{
    string result = "";
    while(n > 0) {
        int rm = n % k;
        if(rm < 10) { result += (rm + '0'); }
        else { result += (rm - 10 + 'A'); }
        n /= k;
    }
    reverse(result.begin(), result.end());
    return result;
}

bool isPrime(long long n)
{
    if(n <= 1) { return false; }
    long long limit = sqrt(n);
    for(long long i=2; i<=limit; ++i) {
        if(n % i == 0) { return false; }
    }
    return true;
}

int solution(int n, int k)
{
    int cnt = 0;
    string ctbn = convertToBase(n, k);

    int idx = 0, lastIdx = 0;
    for(idx=0; idx<ctbn.length(); ++idx) {
        if(ctbn[idx] == '0') {
            if(idx > lastIdx) {
                long long num = stoll(ctbn.substr(lastIdx, (idx-lastIdx)));
                if(isPrime(num)) { cnt++; }
                lastIdx = idx + 1;
            }
        }
    }

    if(lastIdx != idx) {
        long long num = stoll(ctbn.substr(lastIdx, (idx-lastIdx)));
        if(isPrime(num)) { cnt++; }
    }

    return cnt;
}