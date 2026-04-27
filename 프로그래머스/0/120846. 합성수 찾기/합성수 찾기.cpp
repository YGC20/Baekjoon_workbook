#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int result = 0;
    for(int i=1; i<=n; i++) {
        int tmp = 0;
        for(int j=1; j<=i; j++) {
            if(i%j==0) tmp++;
            if(tmp>2) break;
        }
        if(tmp==3) result++;
    }
    return result;
}