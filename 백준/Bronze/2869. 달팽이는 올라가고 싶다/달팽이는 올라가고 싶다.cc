#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int A,B,V,days=0;
    cin>>A>>B>>V;
    if((V-B)%(A-B)==0)
        days=(V-B)/(A-B);
    else
        days=(V-B)/(A-B)+1;
    cout<<days<<"\n";
    return 0;
}