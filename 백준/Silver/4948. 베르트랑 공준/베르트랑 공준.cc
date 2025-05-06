#include <iostream>
using namespace std;
bool isPrime(int n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}
int countPrime(int n){
    int count=0;
    for(int i=n+1;i<=(2*n);i++)
        if(isPrime(i)) count++;
    return count;
}
void bertandsPostulate(void){
    int n;
    while (cin >> n && n != 0)
        cout << countPrime(n) << "\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    bertandsPostulate();
    return 0;
}