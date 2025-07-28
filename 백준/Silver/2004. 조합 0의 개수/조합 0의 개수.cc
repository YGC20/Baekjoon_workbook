#include <iostream>
using namespace std;
int factCount(int num, int x){
    int count=0;
    while(num>0){
        count+=num/x;
        num/=x;
    }
    return count;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N,M;
    cin>>N>>M;
    int fact5 = factCount(N,5)-factCount(M,5)-factCount(N-M,5);
    int fact2 = factCount(N,2)-factCount(M,2)-factCount(N-M,2);
    cout<<min(fact5, fact2)<<"\n";
    return 0;
}