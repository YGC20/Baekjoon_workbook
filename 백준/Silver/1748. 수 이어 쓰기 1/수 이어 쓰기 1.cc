#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    int N;
    cin>>N;
    int NLen = (int)to_string(N).size();
    int idx = 0;
    for(int i=1;i<NLen;++i)
        idx += 9*pow(10,i-1)*i;
    idx += (N-pow(10,NLen-1)+1)*NLen;
    cout<<idx<<"\n";
    return 0;
}