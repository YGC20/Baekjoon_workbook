#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    while(b!=0) {
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}

int solution(int a, int b)
{
    int n = b / gcd(a,b);
    for(int i=2; i*i<=n; i++) {
        while(n%i==0) {
            if(i!=2 && i!=5) return 2;
            n/=i;
        }
    }
    if(n>1 && n!=2 && n!=5) return 2;
    return 1;
}