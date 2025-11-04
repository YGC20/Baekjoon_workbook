#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    vector<int> prime(n+1,0);
    for(int i=2;i<=n;++i)
        prime[i] = i;
    for(int i=2;i<=sqrt(n);++i){
        if(prime[i]==0) continue;
        for(int j=i*2;j<=n;j+=i)
            prime[j] = 0;
    }
    int answer = 0;
    for(int i:prime)
        if(i!=0) answer++;
    return answer;
}