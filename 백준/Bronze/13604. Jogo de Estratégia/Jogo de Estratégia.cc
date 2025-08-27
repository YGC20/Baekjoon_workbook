#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int J,R;
    cin>>J>>R;
    int point[501]={0};
    for(int i=0;i<R;++i){
        for(int j=1;j<=J;++j){
            int num;
            cin>>num;
            point[j]+=num;
        }
    }
    int max=0;
    for(int i=1;i<=J;++i)
        if(point[i]>=max)   max=point[i];
    for(int i=J;i>0;--i)
        if(point[i]==max){
            cout<<i<<"\n";
            break;
        }
    return 0;
}