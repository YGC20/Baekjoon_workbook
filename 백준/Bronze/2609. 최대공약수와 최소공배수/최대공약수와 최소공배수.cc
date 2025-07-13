#include <iostream>
using namespace std;
int gcd(int a, int b){
    return b?gcd(b,a%b):a;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int a,b;
    cin>>a>>b;
    int abGCD = gcd(a,b);
    int abLCM = a*b/abGCD;
    cout<<abGCD<<"\n"<<abLCM<<"\n";
    return 0;
}