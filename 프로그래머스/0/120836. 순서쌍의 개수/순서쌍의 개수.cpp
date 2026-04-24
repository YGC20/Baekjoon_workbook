#include <string>
#include <vector>
using namespace std;

int gcd(int n)
{
    int cnt = 0;
    for(int i=1; i*i<=n; i++) {
        if(n%i==0) {
            if(i*i!=n) cnt++;
            cnt++;
        }
    }
    return cnt;
}

int solution(int n)
{
    return gcd(n);
}