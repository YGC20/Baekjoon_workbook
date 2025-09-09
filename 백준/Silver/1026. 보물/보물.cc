#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> A,B;
    for(int i=0;i<N;++i){
        int num; cin>>num;
        A.push_back(num);
    }
    for(int i=0;i<N;++i){
        int num; cin>>num;
        B.push_back(num);
    }
    sort(A.begin(),A.end());
    sort(B.rbegin(),B.rend());
    int S=0;
    for(int i=0;i<N;++i)    S+=A[i]*B[i];
    cout<<S<<"\n";
    return 0;
}