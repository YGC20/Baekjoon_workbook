#include <vector>
using namespace std;

int gcd(int a, int b){
    int t;
    while(b!=0){
        t=a%b, a=b, b=t;
    }
    return a;
}
int lcm(int a, int b){
    return a*b/gcd(a,b);
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i=1;i<arr.size();++i){
        answer = lcm(answer,arr[i]);
    }
    return answer;
}