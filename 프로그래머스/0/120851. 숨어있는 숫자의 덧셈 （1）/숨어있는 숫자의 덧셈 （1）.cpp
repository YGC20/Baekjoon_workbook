#include <string>
#include <vector>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    for(auto ms : my_string) {
        if('0'<=ms && ms<='9') {
            answer += (ms-'0');
        }
    }
    return answer;
}