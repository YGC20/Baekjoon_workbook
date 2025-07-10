#include <iostream>
using namespace std;
void solution(int n){
    int result = 0;
    for(int i=5;i<501;i*=5)
        result+=n/i;
    cout<<result<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    cin>>N;
    solution(N);
    return 0;
}