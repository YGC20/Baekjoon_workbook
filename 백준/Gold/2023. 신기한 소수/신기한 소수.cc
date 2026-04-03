#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPrime(int number)
{
    for(int i=2; i<=number/2; ++i) {
        if(number%i==0) return false;
    }
    return true;
}

void dfs(int number, int N, int idx)
{
    if(N==idx) {
        if(isPrime(number)) {
            cout<<number<<"\n";
        }
        return;
    }

    for(int i = 1; i<10; ++i) {
        if(i%2==0) {
            continue;
        }
        if(isPrime(number*10+i)) {
            dfs(number*10+i, N, idx+1);
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int N; cin>>N;
    vector<int> num_first = {2, 3, 5, 7};
    for(int nf : num_first) {
        dfs(nf, N, 1);
    }
    return 0;
}