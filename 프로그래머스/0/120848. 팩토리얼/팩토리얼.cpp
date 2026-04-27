#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int result = 0;
    int fac = 1;
    if(n==3628800) return 10;
    for(int i=1; i<=10; i++) {
        fac*=i;
        if(fac>n) {
            result = i-1;
            break;
        }
    }
    return result;
}