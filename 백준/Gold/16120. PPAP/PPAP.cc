#include <iostream>
#include <vector>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    string S;
    cin>>S;
    vector<char> ppap;
    for(int i=0;i<S.length();++i){
        if(S[i]=='P')   ppap.push_back(S[i]);
        else{
            if(ppap.size()>=2&&i+1<S.length()&&S[i+1]=='P'){
                ppap.pop_back();
                i++;
            }
            else{
                cout<<"NP\n";
                return 0;
            }
        }
    }
    if(ppap.size()==1)  cout<<"PPAP\n";
    else    cout<<"NP\n";
    return 0;
}