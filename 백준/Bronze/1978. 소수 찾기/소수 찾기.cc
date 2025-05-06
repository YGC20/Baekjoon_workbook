#include <iostream>
using namespace std;
bool decimalCheck(const int a){
    if(a<2) return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0) return false;
    }
    return true;
}
void decimal(void){
    int N, count=0;
    cin>>N;
    int array[N];
    for(int i=0;i<N;i++)
        cin>>array[i];
    for(int i=0;i<N;i++){
        if(decimalCheck(array[i]))
            count++;
    }
    cout<<count<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    decimal();
    return 0;
}