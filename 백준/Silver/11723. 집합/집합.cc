#include <iostream>
#include <string>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string str;
    int M,S=0,x;
    cin>>M;
    while(M--){
        cin>>str;
        if(str=="add"){
            cin>>x;
            S|=(1<<x);
        }
        else if(str=="remove"){
            cin>>x;
            S&=~(1<<x);
        }
        else if(str=="check"){
            cin>>x;
            if(S&(1<<x))    cout<<"1\n";
            else    cout<<"0\n";
        }
        else if(str=="toggle"){
            cin>>x;
            S^=(1<<x);
        }
        else if(str=="all"){ S=(1<<21)-2; }
        else if(str=="empty"){ S=0; }
    }
    return 0;
}