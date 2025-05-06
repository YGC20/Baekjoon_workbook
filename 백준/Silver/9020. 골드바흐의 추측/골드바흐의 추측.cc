#include <iostream>
using namespace std;
bool isPrime(int n){
    if(n<2) return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}
void goldbachsConjecture(){
    int T, n, i, j, max=0;
    cin>>T;
    for(i=0;i<T;i++){
        cin>>n;
        max=0;
        for(j=2;j<=n/2;j++)
            if(isPrime(j)&&isPrime(n-j))
                if(j>max) max=j;
        cout<<max<<" "<<n-max<<"\n";
    }
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    goldbachsConjecture();
    return 0;
}