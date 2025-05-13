#include <iostream>
#include <vector>
using namespace std;
vector<int> isPrime(int n){
    vector<bool> isPrime(n+1, true);
    vector<int> primes;
    for(int i=2;i<=n;i++)
        if(isPrime[i]){
            primes.push_back(i);
            for(int j=i*2;j<=n;j+=i) isPrime[j]=false;
        }
    return primes;
}
void csopn(void){
    int N, start=0, end=0, sum=0, count=0;
    cin>>N;
    vector<int> primes=isPrime(N);
    while(true){
        if(sum>N) sum-=primes[start++];
        else if(end==primes.size()) break;
        else sum+=primes[end++];
        if(sum==N) count++;
    }
    cout<<count<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    csopn();
    return 0;
}