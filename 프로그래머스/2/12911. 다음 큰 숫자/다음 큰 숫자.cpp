#include <string>
#include <vector>

using namespace std;

int to_binary_count(int num){
    int cnt = 0;
    while(num>0){
        if(num%2==1) cnt++;
        num>>=1;
    }
    return cnt;
}

int solution(int n) {
    int answer = n+1;
    int n_one = to_binary_count(n);
    while(true){
        if(to_binary_count(answer)==n_one) break;
        answer++;
    }
    return answer;
}