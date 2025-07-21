#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> qm;
int gcd(int a, int b){
    int tmp;
    while(b>0){
        tmp=a;
        a=b;
        b=tmp%a;
    }
    return a;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    cin>>N;
    vector<int> M(N);
    for(int i=0;i<N;i++)
        cin>>M[i];
    sort(M.begin(),M.end());
    int g=M[1]-M[0];
    for(int i=2;i<N;i++)
        g=gcd(g,M[i]-M[i-1]);
    
    vector<int> divs;
    for(int i=2;i*i<=g;i++){
        if(g%i==0){
            divs.push_back(i);
            if(i*i!=g)
                divs.push_back(g/i);
        }
    }
    divs.push_back(g);
    sort(divs.begin(),divs.end());
    for(int div:divs)
        cout<<div<<" ";
    cout<<"\n";
    return 0;
}