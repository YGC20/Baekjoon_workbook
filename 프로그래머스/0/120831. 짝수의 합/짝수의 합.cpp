#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    do {
        if(n%2==0) answer+=n;
    } while(n--);
    return answer;
}